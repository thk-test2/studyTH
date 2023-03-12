function printName(firstname) {
    var myname = "jisu";
    return myname + " ," +  firstname;
}

// 13, 7, 8, 9, (1, 2, 3, 4), 9(result), 10, 11
function run(firstname) {
   firstname = firstname || "Youn";
   var result = printName(firstname);
   console.log(result);
}

run('THK')