
function run() {
    setTimeout(function() {
        var msg = "hello";
        console.log(msg);
    }, 2000);
}

console.log("start");
run();
console.log("end");