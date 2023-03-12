
function a() {
    if (arguments.length < 3) return;
    
    console.log(arguments);

    for (var i = 0; i < arguments.length; i++) {
        console.log(arguments[i]);
    }

}

a(1, 2, "THK");