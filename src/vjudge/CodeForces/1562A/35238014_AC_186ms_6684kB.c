// !Typescript

/*
import { stdin, exit } from "process";
stdin.resume();
let ori: string;
stdin.on("readable", () => {
    let chunk: Buffer | null = stdin.read();
    if (chunk) {
        ori += chunk.toString();
    }
});
stdin.on("end", () => {
    let input = ori.trim().split("\n");
    for (let i = 1; i < input.length; ++i) {
        let [l, r]: number[] = input[i].split(" ").map((x: string) => parseInt(x));
        console.log(l <= Math.floor(r / 2 + 1) ? r % Math.floor(r / 2 + 1) : r % l);
    }
    exit(0);
});
*/

"use strict";exports.__esModule=true;var process_1=require("process");process_1.stdin.resume();var ori;process_1.stdin.on("readable",function(){var chunk=process_1.stdin.read();if(chunk){ori+=chunk.toString()}});process_1.stdin.on("end",function(){var input=ori.trim().split("\n");for(var i=1;i<input.length;++i){var _a=input[i].split(" ").map(function(x){return parseInt(x)}),l=_a[0],r=_a[1];console.log(l<=Math.floor(r/2+1)?r%Math.floor(r/2+1):r%l)}(0,process_1.exit)(0)});