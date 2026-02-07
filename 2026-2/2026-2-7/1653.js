/**
 * @param {string} s
 * @return {number}
 */
var minimumDeletions = function(s) {
    let counta = 0;
    let countb = 0;
    for(let i = 0; i < s.length; i ++)
    {
        if(s[i] == 'a')
            counta ++;
        else
            countb ++;
    }
    let nowa = 0, nowb = 0;
    let mindelete = counta;
    let nowdelete = 0;
    for(let i = 0; i < s.length; i ++)
    {
        if(s[i] == 'a')
            nowa ++;
        else
            nowb ++;
        nowdelete = counta + nowb - nowa;
        mindelete = nowdelete < mindelete ? nowdelete : mindelete;
    }
    return mindelete;
};