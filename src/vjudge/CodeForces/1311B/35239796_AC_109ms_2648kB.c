// !TypeScript

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
    let input = (function* () {
        let tmp = ori.trim().split('\n').slice(1);
        for (let x in tmp) {
            yield tmp[x];
        }
        return;
    })();
    let getNextLineAsNumber = () => {
        return (input.next().value as string).split(' ').map(x => parseInt(x));
    }
    let indexOfLastMax = (val: number[]): number => {
        let res = 0;
        for (let i = 0; i < val.length; ++i) {
            if (val[i] >= val[res]) {
                res = i;
            }
        }
        return res;
    }
    while (true) {
        let oriNM = input.next();
        if (oriNM.done) {
            break;
        }
        let [n, m] = (oriNM.value as string).split(' ').map(x => parseInt(x));
        let a: number[] = getNextLineAsNumber();
        let p: number[] = getNextLineAsNumber();
        let b: Set<number> = new Set<number>();
        for (let i = 0; i < p.length; ++i) {
            b.add(p[i] - 1);
        }
        let flag: boolean = false;
        for (let i = 0; i < a.length; ++i) {
            let cur = indexOfLastMax(a.slice(0, a.length - i));
            for (let j = cur; j < a.length - i - 1; ++j) {
                if (!b.has(j)) {
                    flag = true;
                    break;
                }
                let t: number = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
        console.log(flag ? "NO" : "YES");
    }
    exit(0);
});
*/

"use strict";var __generator=this&&this.__generator||function(thisArg,body){var _={label:0,sent:function(){if(t[0]&1)throw t[1];return t[1]},trys:[],ops:[]},f,y,t,g;return g={next:verb(0),throw:verb(1),return:verb(2)},typeof Symbol==="function"&&(g[Symbol.iterator]=function(){return this}),g;function verb(n){return function(v){return step([n,v])}}function step(op){if(f)throw new TypeError("Generator is already executing.");while(_)try{if(f=1,y&&(t=op[0]&2?y["return"]:op[0]?y["throw"]||((t=y["return"])&&t.call(y),0):y.next)&&!(t=t.call(y,op[1])).done)return t;if(y=0,t)op=[op[0]&2,t.value];switch(op[0]){case 0:case 1:t=op;break;case 4:_.label++;return{value:op[1],done:false};case 5:_.label++;y=op[1];op=[0];continue;case 7:op=_.ops.pop();_.trys.pop();continue;default:if(!(t=_.trys,t=t.length>0&&t[t.length-1])&&(op[0]===6||op[0]===2)){_=0;continue}if(op[0]===3&&(!t||op[1]>t[0]&&op[1]<t[3])){_.label=op[1];break}if(op[0]===6&&_.label<t[1]){_.label=t[1];t=op;break}if(t&&_.label<t[2]){_.label=t[2];_.ops.push(op);break}if(t[2])_.ops.pop();_.trys.pop();continue}op=body.call(thisArg,_)}catch(e){op=[6,e];y=0}finally{f=t=0}if(op[0]&5)throw op[1];return{value:op[0]?op[1]:void 0,done:true}}};exports.__esModule=true;var process_1=require("process");process_1.stdin.resume();var ori;process_1.stdin.on("readable",function(){var chunk=process_1.stdin.read();if(chunk){ori+=chunk.toString()}});process_1.stdin.on("end",function(){var input=function(){var tmp,_a,_b,_i,x;return __generator(this,function(_c){switch(_c.label){case 0:tmp=ori.trim().split("\n").slice(1);_a=[];for(_b in tmp)_a.push(_b);_i=0;_c.label=1;case 1:if(!(_i<_a.length))return[3,4];x=_a[_i];return[4,tmp[x]];case 2:_c.sent();_c.label=3;case 3:_i++;return[3,1];case 4:return[2]}})}();var getNextLineAsNumber=function(){return input.next().value.split(" ").map(function(x){return parseInt(x)})};var indexOfLastMax=function(val){var res=0;for(var i=0;i<val.length;++i){if(val[i]>=val[res]){res=i}}return res};while(true){var oriNM=input.next();if(oriNM.done){break}var _a=oriNM.value.split(" ").map(function(x){return parseInt(x)}),n=_a[0],m=_a[1];var a=getNextLineAsNumber();var p=getNextLineAsNumber();var b=new Set;for(var i=0;i<p.length;++i){b.add(p[i]-1)}var flag=false;for(var i=0;i<a.length;++i){var cur=indexOfLastMax(a.slice(0,a.length-i));for(var j=cur;j<a.length-i-1;++j){if(!b.has(j)){flag=true;break}var t=a[j];a[j]=a[j+1];a[j+1]=t}}console.log(flag?"NO":"YES")}(0,process_1.exit)(0)});