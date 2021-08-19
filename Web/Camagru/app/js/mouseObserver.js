let mouseX = -1;
let mouseY = -1;

document.addEventListener(
    'mousemove',
    function(event) {
        mouseX = event.clientX;
        mouseY = event.clientY;
    }
);