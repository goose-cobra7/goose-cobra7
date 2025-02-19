document.addEventListener('DOMContentLoaded', function () {
    const sublist = document.querySelector('.sublist');
    setTimeout(() => {
      sublist.classList.add('show');
    }, 500); // Adjust the delay as needed
  });