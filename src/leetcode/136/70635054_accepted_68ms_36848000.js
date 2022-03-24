/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    var ret = 0;
    for(var x of nums) ret ^= x;
    return ret;
};