<div class="responsive-content">
    <h1 id="title">Create new post</h1>

    <div id="source-selection-state">
        <div id="source-buttons">
            <button id="start-camera" class="source-button">
                <img src="data/images/elements/photo-camera.svg" alt="Select file">
                Take a new photo
            </button>
            <button id="load-photo" class="source-button">
                <img src="data/images/elements/file.svg" alt="Select file">
                Load a photo from disk
            </button>
            <input id="file-input" type="file" accept="image/*" style="display: none;"/>
        </div>
    </div>

    <div id="camera-state">
        <video id="video" autoplay></video>
        <button id="take-photo">Take photo</button>
    </div>

    <div id="photo-state" class="image-control-panel">
        <canvas id="photo-canvas" class="canvas"></canvas>
        <div class="image-control-buttons">
            <button id="retake-photo">Retake</button>
            <button id="use-photo">Use</button>
        </div>
    </div>

    <div id="file-state" class="image-control-panel">
        <div class="canvas-holder">
            <canvas id="file-canvas" class="canvas">Canvas</canvas>
        </div>
        <div class="image-control-buttons">
            <button id="reload-file">Load another file</button>
            <button id="use-file">Use this file</button>
        </div>
    </div>

    <div id="post-state">
        <div class="canvas-holder bottom-offset">
            <canvas id="post-canvas" class="canvas">Canvas</canvas>
        </div>

        <div id="stickers-container"></div>

        <div id="master-stickers-container" class="bottom-offset">
            <img id="sticker-1" class="sticker" src="data/images/stickers/1.png"">
            <img id="sticker-2" class="sticker" src="data/images/stickers/2.png"">
            <img id="sticker-3" class="sticker" src="data/images/stickers/3.png"">
            <img id="sticker-4" class="sticker" src="data/images/stickers/4.png"">
        </div>

        <textarea id="post-text" class="bottom-offset"></textarea>
        <button id="post-button">Post!</button>
    </div>
</div>
<script src="js/canvasTools.js"></script>
<script src="js/mouseObserver.js"></script>
<script src="js/geometryTools.js"></script>
<script src="js/stickerTools.js"></script>
<script>
    //  Tools

    function hideElement(element) {
        element.style.display = 'none';
    }

    function showElement(element) {
        element.style.display = 'block';
    }

    function hideAllStatesDivs() {
        hideElement(divOfSourceSelectionState);
        hideElement(divOfCameraState);
        hideElement(divOfPhotoState);
        hideElement(divOfFileState);
        hideElement(divOfPostState);
    }

    function copyCanvas(source, destination) {
        destination.style.width = source.style.width;
        destination.style.height = source.style.height;

        destination.width = source.width;
        destination.height = source.height;

        destination.getContext('2d').drawImage(source, 0, 0);
    }

    //  Source selection state

    function switchToSourceSelectionState() {
        hideAllStatesDivs();
        showElement(divOfSourceSelectionState);
    }

    const divOfSourceSelectionState = document.querySelector("#source-selection-state");

    document.querySelector("#load-photo").onclick = () => {
        const fileInput = document.querySelector("#file-input");

        fileInput.onclick = () => fileInput.value = null;
        fileInput.onchange = () => {
            const imageFile = fileInput.files[0];

            resetCanvasSize(fileCanvas);

            const image = new Image();
            image.onload = () => {
                switchToFileState();
                resizeCanvasAccordingToImage(fileCanvas, image);
            }
            image.src = URL.createObjectURL(imageFile);
        };

        fileInput.click();
    };

    document.querySelector("#start-camera").onclick = async () => {
        const promise = navigator.mediaDevices.getUserMedia(
            {
                video: true,
                audio: false,
            }
        );

        promise.then(
            mediaStream => {
                video.srcObject = mediaStream;
                switchToCameraState();
            },
            () => {
            }
        )
    };

    //  Camera state

    function switchToCameraState() {
        hideAllStatesDivs();
        showElement(divOfCameraState);
    }

    const divOfCameraState = document.querySelector("#camera-state");
    const video = document.querySelector("#video");

    document.querySelector("#take-photo").onclick = () => {
        photoCanvas.style.height = video.getBoundingClientRect().height + 'px';
        switchToPhotoState();
        fixCanvasSize(photoCanvas);
        photoCanvas.getContext('2d').drawImage(video, 0, 0, photoCanvas.width, photoCanvas.height);
    }

    //  Photo state

    function switchToPhotoState() {
        hideAllStatesDivs();
        showElement(divOfPhotoState);
    }

    const divOfPhotoState = document.querySelector("#photo-state");
    const photoCanvas = document.querySelector("#photo-canvas");

    document.querySelector("#retake-photo").onclick = () => {
        switchToCameraState();
    }

    document.querySelector("#use-photo").onclick = () => {
        copyCanvas(photoCanvas, postCanvas);
        switchToPostState();
    };

    //  File state

    function switchToFileState() {
        hideAllStatesDivs();
        showElement(divOfFileState);
    }

    const divOfFileState = document.querySelector("#file-state");
    const fileCanvas = document.querySelector("#file-canvas");

    document.querySelector("#reload-file").onclick = () => {
        switchToSourceSelectionState();
    };

    document.querySelector("#use-file").onclick = () => {
        copyCanvas(fileCanvas, postCanvas);
        switchToPostState();
    };

    //  Post state

    function switchToPostState() {
        hideAllStatesDivs();
        showElement(divOfPostState);
    }

    function setupStickers() {
        let stickers = document.querySelectorAll(".sticker");
        for (let i = 0; i < stickers.length; i++)
            makeStickerMaster(stickers[i], postCanvas, stickersContainer);
    }

    function printStickersOnCanvas() {
        let stickers = document.querySelectorAll(".sticker");

        for (let i = 0; i < stickers.length; i++) {
            const sticker = stickers[i];
            if (isStickerOnCanvas(sticker, postCanvas)) {
                printOnCanvas(postCanvas, sticker);
            }
        }
    }

    function saveImageOnServer(canvas, successCallback) {
        fetch(
            'http://localhost/php/scripts/savePostImage.php',
            {
                method: 'POST',
                body: canvas.toDataURL("image/png")
            }
        ).then(
            response => response.text()
        ).then(
            imageId => successCallback(imageId)
        ).catch(
            error => console.log(error)
        );
    }

    function createPost(imageId) {
        fetch(
            'http://localhost/php/scripts/createPost.php',
            {
                method: 'POST',
                body: JSON.stringify({
                    image_id: imageId,
                    text: postText.value
                })
            }
        ).then(
            response => response.text()
        ).then(
            result => console.log(result)
        ).catch(
            error => console.log(error)
        );
    }

    const divOfPostState = document.querySelector("#post-state");
    const postCanvas = document.querySelector("#post-canvas");
    const stickersContainer = document.querySelector("#stickers-container");
    const postText = document.querySelector("#post-text");

    document.querySelector("#post-button").onclick = () => {
        printStickersOnCanvas();
        saveImageOnServer(postCanvas, createPost);
    };

    //  Setup

    switchToSourceSelectionState();
    setupStickers();
</script>