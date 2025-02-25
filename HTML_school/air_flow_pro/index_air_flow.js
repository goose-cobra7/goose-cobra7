// Fetch component data from JSON
fetch('components.json')
    .then(response => response.json())
    .then(data => {
        initializeApp(data);
    });

function initializeApp(data) {
    const componentTypes = data.componentTypes;
    const cases = data.cases;
    const motherboardTypes = data.motherboardTypes;

    // Data structures and components
    class Component {
        constructor(name, type, dimensions, airflowImpact, heatOutput, color) {
            this.name = name;
            this.type = type;
            this.dimensions = dimensions;  // [length, width, height]
            this.airflowImpact = airflowImpact;
            this.heatOutput = heatOutput;
            this.color = color || '#3498db'; // Default color
            this.isPlaced = false;
        }
    }

    class FanSlot {
        constructor(position, size) {
            this.position = position; // [x, y, z]
            this.size = size;         // [length, width]
            this.occupied = false;
        }
    }

    class Case {
        constructor(dimensions, fanSlots) {
            this.dimensions = dimensions; // [length, width, height]
            this.components = [];
            this.fanSlots = fanSlots;     // Array of FanSlot objects
        }

        addComponent(component) {
            this.components.push(component);
            component.isPlaced = true;
        }

        removeComponent(component) {
            this.components = this.components.filter(c => c !== component);
            component.isPlaced = false;
        }

        getComponents() {
            return this.components;
        }

        getAvailableFanSlot() {
            return this.fanSlots.find(slot => !slot.occupied);
        }

        occupyFanSlot(component, slot) {
            slot.occupied = true;
            component.position = slot.position;
        }

        displayFanSlots() {
            this.fanSlots.forEach(slot => {
                const div = document.createElement('div');
                div.classList.add('fan-slot');
                div.style.width = `${slot.size[0]}px`;
                div.style.height = `${slot.size[1]}px`;
                div.style.position = 'absolute';
                div.style.left = `${slot.position[0]}px`;
                div.style.top = `${slot.position[1]}px`;
                div.style.border = '2px dashed #2c3e50';
                pcCaseElement.appendChild(div);
            });
        }
    }

    const defaultCase = cases.find(c => c.name === "Default Case");
    const pcCase = new Case([50, 20, 50], defaultCase.fanSlots);

    const components = componentTypes.map(ct => new Component(ct.type, ct.type, ct.dimensions, ct.airflowImpact, ct.heatOutput));

    const addBtn = document.querySelector('.add-btn');
    const componentsList = document.getElementById('components-list');
    const pcCaseElement = document.querySelector('.pc-case');
    const componentTypeDropdown = document.getElementById('component-type-dropdown');
    const componentDropdown = document.getElementById('component-dropdown');

    addBtn.addEventListener('click', addComponent);
    pcCaseElement.addEventListener('dragover', dragOver);
    pcCaseElement.addEventListener('drop', dropComponent);
    componentTypeDropdown.addEventListener('change', populateComponentDropdown);

    populateComponentTypeDropdown();
    pcCase.displayFanSlots();

    function populateComponentTypeDropdown() {
        componentTypes.forEach(type => {
            const option = document.createElement('option');
            option.value = type.type;
            option.textContent = type.type;
            componentTypeDropdown.appendChild(option);
        });
    }

    function populateComponentDropdown() {
        const selectedType = componentTypeDropdown.value;
        componentDropdown.innerHTML = '<option value="">Select Component</option>'; // Reset
        components
            .filter(component => component.type === selectedType)
            .forEach(component => {
                const option = document.createElement('option');
                option.value = component.name;
                option.textContent = component.name;
                componentDropdown.appendChild(option);
            });
    }

    function addComponent() {
        const name = prompt('Enter component name:');
        const type = componentDropdown.value;
        if (!type) {
            alert('Please select a component type and component!');
            return;
        }
        const selectedType = componentTypes.find(c => c.type === type);
        if (selectedType) {
            const component = new Component(name, selectedType.type, selectedType.dimensions, selectedType.airflowImpact, selectedType.heatOutput);
            components.push(component);
            updateComponentsList();
        } else {
            alert('Invalid component type!');
        }
    }

    function updateComponentsList() {
        componentsList.innerHTML = '';
        components.forEach(component => {
            if (!component.isPlaced) {
                const li = document.createElement('li');
                li.textContent = component.name;
                li.style.color = component.color;
                li.draggable = true;
                li.addEventListener('dragstart', dragStart);
                li.addEventListener('contextmenu', (e) => {
                    e.preventDefault();
                    deleteComponent(component);
                });
                componentsList.appendChild(li);
            }
        });
    }

    function dragStart(e) {
        e.dataTransfer.setData('text/plain', e.target.textContent);
    }

    function dragOver(e) {
        e.preventDefault();
    }

    function dropComponent(e) {
        e.preventDefault();
        const componentName = e.dataTransfer.getData('text/plain');
        const component = components.find(c => c.name === componentName);
        if (component && !component.isPlaced) {
            if (component.type === "Fan") {
                const slot = pcCase.getAvailableFanSlot();
                if (slot) {
                    pcCase.occupyFanSlot(component, slot);
                    placeComponentInCase(component, slot);
                } else {
                    alert('No available slots for fan!');
                }
            } else {
                placeComponentInCase(component, { x: e.offsetX, y: e.offsetY });
            }
        }
    }

    function selectComponent(name) {
        return components.find(component => component.name === name);
    }

    function placeComponentInCase(component, position) {
        const div = document.createElement('div');
        div.textContent = component.name;
        div.classList.add('component');
        div.style.backgroundColor = component.color;
        div.style.width = `${component.dimensions[0]}px`;
        div.style.height = `${component.dimensions[1]}px`;
        div.style.position = 'absolute';
        div.style.left = `${position.x}px`;
        div.style.top = `${position.y}px`;
        div.draggable = true;
        div.addEventListener('dragstart', dragStart);
        div.addEventListener('contextmenu', (e) => {
            e.preventDefault();
            deleteComponentFromCase(component, div);
        });
        pcCaseElement.appendChild(div);
        pcCase.addComponent(component);
    }

    function deleteComponent(component) {
        components.splice(components.indexOf(component), 1);
        updateComponentsList();
    }

    function deleteComponentFromCase(component, element) {
        if (component.type === "Fan") {
            const slot = pcCase.fanSlots.find(slot => slot.position === component.position);
            slot.occupied = false;
        }
        pcCase.removeComponent(component);
        element.remove();
    }

    updateComponentsList();
}
