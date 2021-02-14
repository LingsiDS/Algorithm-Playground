/**
 * @param {string} s
 * @return {string}
 */
var sortString = function(s) {
    var bkt = new Array(26).fill(0);
    for (let c of s) bkt[c.charCodeAt() - 'a'.charCodeAt()]++;
    var res = "";
    while (res.length < s.length) {
        for (let i = 0; i < 26; i++) {
            if (bkt[i]) {
                res += String.fromCharCode('a'.charCodeAt() + i);
                bkt[i]--;
            }
        }
        for (let i = 25; i >= 0; i--) {
            if (bkt[i]) {
                res += String.fromCharCode('a'.charCodeAt() + i);
                bkt[i]--;
            }
        }
    }
    return res;
};