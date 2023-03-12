
// function printName(firstname) {
//     return "name is " + firstname;
// }

// console.log(printName('THK', 'TEST'));


function printName(firstname) {

    console.log(typeof inner);
    var result = inner();

    function inner() {
        return "inner value";
    }
    // var inner = function() {
    //     return "inner value";
    // }

    console.log("name is " + result);
}

printName();