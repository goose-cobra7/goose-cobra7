#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_PHONE_NUMBER_LENGTH 16
#define MAX_MESSAGE_LENGTH 161
#define MAX_TIMESTAMP_LENGTH 32

#define SMS_UNREAD 0
#define SMS_READ 1
#define SMS_FAILED 2
#define SMS_SENT 3

typedef struct {
    char sender[MAX_PHONE_NUMBER_LENGTH];
    char receiver[MAX_PHONE_NUMBER_LENGTH];
    char timestamp[MAX_TIMESTAMP_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    int status;
} SMSMessage;

typedef struct MessageNode
{
    SMSMessage message;
	struct MessageNode* next;
	struct MessageNode* prev;
}MessageNode;

typedef struct {
    MessageNode* head;
    MessageNode* tail;
} Conversation;
Conversation add_mess_to_tail(Conversation *con,SMSMessage SMS);
Conversation getConversationFromFile(const char* fileName);
void printConversation(Conversation conversation);
void freeConversation(Conversation* conversation);

int main()
{
    Conversation conversation = getConversationFromFile("sms_inbox.dat");

   printConversation(conversation);

    freeConversation(&conversation);

    return 0;
}

void printConversation(Conversation conversation)
{
	MessageNode *temp;
	temp = conversation.head;
	int status;
	while (temp)
	{
		printf("--------------------------\n");
		printf("Reader:  %s\n",temp->message.receiver);
		printf("To:      %s\n",temp->message.receiver);
		printf("Time:    %s\n",temp->message.timestamp);
		status = temp->message.status;
		switch (status)
		{
		case SMS_UNREAD:
			printf("status:  unread\n");
			break;
		case SMS_READ:
			printf("status:  read\n");
			break;
		case SMS_SENT:
			printf("status:  sent\n");
			break;
		default:
			printf("status:  failed\n");
			break;
		}
		printf("messege: %s\n",temp->message.message);
		temp = temp->next;
	}	
}

Conversation getConversationFromFile(const char* fileName)
{
	//create new conv holder
	Conversation import_con;
	import_con.head = NULL;
	import_con.tail = NULL;
	//open file and buffer
	FILE *pfile = fopen("sms_inbox.dat","rb");
	if(!pfile){printf("error: file_opening_problem");exit(-1);}
	SMSMessage buffer;
	//while still have somthing to read
	while (fread(&buffer,sizeof(SMSMessage),1,pfile)==1)
	{
		add_mess_to_tail(&import_con,buffer);
	}
	fclose(pfile);
	return import_con;
}


Conversation add_mess_to_tail(Conversation *con,SMSMessage SMS)
{
	//create new node and put SMS in it
	MessageNode *new_node = malloc(sizeof(MessageNode));
	if(!new_node){printf("error: new_node_memory_outage");exit(-1);}
	new_node->message = SMS;
	//case1: conv is empty
	if(con->head == NULL)
	{
		con->head = new_node;
		con->tail = new_node;
	}else //case2: existing conv
	{
		con->tail->next = new_node;
		new_node->prev = con->tail;
		con->tail = new_node;
	}
}

void freeConversation(Conversation* conversation)
{
	MessageNode* current = conversation->head;
	while (current != NULL)
	{
		MessageNode* temp = current->next;
		free(current);
		current = temp;
	}
	conversation->head = NULL;
	conversation->tail = NULL;
}