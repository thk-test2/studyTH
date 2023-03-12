
var el = document.querySelector(".outside");

el.addEventListener("click", function(evt) {
    console.log("clicked", evt);
    var target = evt.target;
   console.log(target.className, target.nodeName); 
});