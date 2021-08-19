function makeStickerMaster(master, canvas, stickersContainer) {
    master.addEventListener('mousedown', copyOnCanvas);

    function copyOnCanvas() {
        const copy = master.cloneNode();
        stickersContainer.append(copy);

        makeSticker(copy, canvas, alignStickerWithCanvas(copy, canvas));
    }

    function alignStickerWithCanvas(sticker, canvas) {
        const canvasRect = canvas.getBoundingClientRect();
        const stickerRect = sticker.getBoundingClientRect();

        const canvasCenter = new DOMPoint(
            canvasRect.left / 2 + canvasRect.right / 2,
            canvasRect.bottom / 2 + canvasRect.top / 2
        );

        const stickerCenter = new DOMPoint(
            stickerRect.left / 2 + stickerRect.right / 2,
            stickerRect.bottom / 2 + stickerRect.top / 2
        );

        return new DOMPoint(
            canvasCenter.x - stickerCenter.x,
            canvasCenter.y - stickerCenter.y
        );
    }
}

function makeSticker(sticker, canvas, initialOffset) {
    let initialX = 0;
    let initialY = 0;

    let offsetX = initialOffset.x;
    let offsetY = initialOffset.y;

    sticker.style.z = 1000;

    moveStickerOn(sticker, offsetX, offsetY);
    sticker.addEventListener('mousedown', startDragging);

    function startDragging(event) {
        event.preventDefault();

        initialX = mouseX - offsetX;
        initialY = mouseY - offsetY;

        window.addEventListener('mousemove', doDragging);
        this.addEventListener('mouseup', finishDragging);
    }

    function doDragging(event) {
        event.preventDefault();

        const newX = mouseX - initialX;
        const newY = mouseY - initialY;

        offsetX = newX;
        offsetY = newY;

        moveStickerOn(sticker, newX, newY);
    }

    function finishDragging(event) {
        event.preventDefault();

        window.removeEventListener('mousemove', doDragging);
        this.removeEventListener('mouseup', finishDragging);

        if (!isStickerOnCanvas(sticker, canvas))
            destroySticker();
    }

    function destroySticker() {
        sticker.remove();
    }
}

function moveStickerOn(sticker, x, y) {
    sticker.style.transform = "translate3d(" + x + "px, " + y + "px, 0)";
}

function isStickerOnCanvas(sticker, canvas) {
    const canvasRect = canvas.getBoundingClientRect();
    const stickerRect = sticker.getBoundingClientRect();

    return doRectsIntersect(stickerRect, canvasRect);
}