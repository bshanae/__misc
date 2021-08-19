function printOnCanvas(canvas, image) {
    const canvasRect = canvas.getBoundingClientRect();
    const imageRect = image.getBoundingClientRect();

    const offsetImageToCanvasLeft = imageRect.left - canvasRect.left;
    const offsetImageToCanvasTop = imageRect.top - canvasRect.top;

    canvas.getContext('2d').drawImage(
        image,
        offsetImageToCanvasLeft,
        offsetImageToCanvasTop,
        image.width,
        image.height
    );
}

function resetCanvasSize(canvas) {
    canvas.style.width = '';
    canvas.style.height = '';
}

function resizeCanvasAccordingToImage(canvas, image) {
    if (canvas.width > image.width) {
        canvas.style.width = image.width + 'px';
        canvas.style.height = image.height + 'px';
    } else {
        const aspectRatio = image.width / image.height;
        canvas.style.height = canvas.getBoundingClientRect().width / aspectRatio + 'px';
    }

    fixCanvasSize(canvas);
    canvas.getContext('2d').drawImage(image, 0, 0, canvas.width, canvas.height);
}

function fixCanvasSize(canvas) {
    const rect = canvas.getBoundingClientRect();

    canvas.width = rect.width;
    canvas.height = rect.height;
}