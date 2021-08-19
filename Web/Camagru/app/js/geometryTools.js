function doRectsIntersect(rectA, rectB) {
    const rectATopLeft = new DOMPoint(rectA.left, rectA.top);
    const rectATopRight = new DOMPoint(rectA.right, rectA.top);
    const rectABottomRight = new DOMPoint(rectA.right, rectA.bottom);
    const rectABottomLeft = new DOMPoint(rectA.left, rectA.bottom);

    return isPointInsideRect(rectATopLeft, rectB) ||
           isPointInsideRect(rectATopRight, rectB) ||
           isPointInsideRect(rectABottomRight, rectB) ||
           isPointInsideRect(rectABottomLeft, rectB);
}

function isPointInsideRect(point, rect) {
    const rectMin = new DOMPoint(rect.x, rect.y);
    const rectMax = new DOMPoint(rect.x + rect.width, rect.y + rect.height);

    return point.x >= rectMin.x &&
           point.y >= rectMin.y &&
           point.x <= rectMax.x &&
           point.y <= rectMax.y;
}