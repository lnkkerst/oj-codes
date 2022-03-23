"use strict";
exports.__esModule = true;
var process_1 = require("process");
process_1.stdin.resume();
var ori;
process_1.stdin.on("readable", function () {
    var chunk = process_1.stdin.read();
    if (chunk) {
        ori += chunk.toString();
    }
});
process_1.stdin.on("end", function () {
    var input = ori.trim().split("\n");
    for (var i = 1; i < input.length; ++i) {
        var _a = input[i].split(' ').map(function (x) { return parseInt(x); }), a = _a[0], b = _a[1];
        if (a === b) {
            console.log(0);
        }
        else if ((a > b && (a - b) % 2 === 0) || (a < b && (b - a) % 2 === 1)) {
            console.log(1);
        }
        else {
            console.log(2);
        }
    }
    (0, process_1.exit)(0);
});
