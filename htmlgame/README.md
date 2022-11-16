# html game 2048

> html 코드

```html
<!DOCTYPE html>
<html style = "background-color : blueviolet">
<head>
    <title>2048 puzzle upgrade.ver</title>
</head>

<body>
	<center>
		<h1 style = "color : blue">2048 변형 게임</h1>
		<div style = "display : flex; justify-content: space-between; width : 45%">
		<div >
			<a  style="cursor: pointer; padding-left: 10%; " onclick="return load(1);">
				<button  id = "mode1" class = "startbtn" 
				style = "border-radius: 5px; border: none; background-color: #99FFCC; color  : balck;">easy
			</button>
			</a>
		</div>
		<div>
			<a   style="cursor: pointer; padding-left: 10%; " onclick="return load(2);">
				<button id = "mode2" class = "startbtn" style = "border-radius: 5px; border: none; background-color: #99FFCC; color  : balck;">nomal</button>
			</a>
		</div>
		<div>
			<a  style="cursor: pointer; padding-left: 10%; " onclick="return load(3);">
				<button id = "mode3" class = "startbtn" style = "border-radius: 5px; border: none; background-color: #99FFCC; color  : balck;">hard</button>
			</a>
		</div>
    </div>
	<div id="canvas"></div>	
	<h2>Score :  <div style="display:inline;" id="score"></div></h2>
	<h2>Best Score :  <div style="display:inline;" id="best_score">0</div></h2>
	<b>HOW TO PLAY:</b> Use your arrow keys to move the tiles.
	</center>
	<script type="text/javascript">
	//Size of the grid
	var size;
    var min
    var max;
    var isMoved = false;
    var score = 0;
	var best_score = 0;
    var excludeIds = [];
    function load(len) {

		size = box_size(len);
		min = 0;
		max = size-1;
		//alert("load");
		//Load the table

		var html = '<table border="1" style = "border-color : #99CCFF">';
		for(var row=0;row<size;row++) {
			html += '<tr>';
			for(var col=0;col<size;col++) {
				var id = row+""+col;
				html += '<td align="center" valign="center" height="40" width="40" id="'+id+'"></td>';
			}
			html += '</tr>';
		}
		html += '</table>';
		document.getElementById("canvas").innerHTML = html;
        document.getElementById("canvas").style.color = "white";

		var id1 = getId();
		var id2 = "";
		while(true) {
			id2 = getId();
			if(id1 != id2)
			break;
		}
		//Set initial 2 values
		document.getElementById(id1).innerHTML = "3";
		document.getElementById(id2).innerHTML = "3";

		document.getElementById(id1).style.backgroundColor = getColor(3);
		document.getElementById(id2).style.backgroundColor = getColor(3);
		
		score = 0;
		document.getElementById("score").innerHTML = score;
		// document.getElementById("best_score").innerHTML = best_score;

		return false;
	}
	
    function box_size(len){
		if (len == 1){
			var size = 6;
		}
		else if(len == 2){
			var size = 5;
		}
		else if(len == 3){
			var size = 4;
		}
		else var size = 6;
		return size;
    }

	function getRandom()
	{
		return Math.floor(Math.random()*(max-min+1)+min);
	}
	function getId()
	{
		var i = getRandom();
		var j = getRandom();
		return i+""+j;
	}
	function up() {
		isMoved = false;
		excludeIds = [];
		for(var j=min;j<=max;j++) {
			for(var i=min;i<=max;i++) {
				var id = i+""+j;
				if(document.getElementById(id).innerHTML != "") {
					moveUp(id);
				}
			}
		}
		if(isMoved == true) {
			update();
		}
		return false;
	}
	function moveUp(id) {		
		if(!id.startsWith(min)) {
			var arr = id.split("");
			var i = parseInt(arr[0]);
			var j = parseInt(arr[1]);
			for(var k=(i-1);k>=min;k--) {
				var nId = k+""+j;
				if(document.getElementById(nId).innerHTML != "") {
					var val = parseInt(document.getElementById((k+1)+""+j).innerHTML);
					var nVal = parseInt(document.getElementById(nId).innerHTML);
					if(val == nVal) {
						if(excludeIds.indexOf(nId) == -1){
							excludeIds.push(nId);
							document.getElementById(nId).innerHTML = (val+nVal);
							document.getElementById(nId).style.backgroundColor = getColor((val+nVal));
							document.getElementById((k+1)+""+j).innerHTML = "";
							document.getElementById((k+1)+""+j).style.backgroundColor = "blueviolet";
							isMoved = true;
							score += (val+nVal);
						}
					}
					break;
				}
				else {
					document.getElementById(nId).innerHTML = document.getElementById((k+1)+""+j).innerHTML;
					document.getElementById(nId).style.backgroundColor = document.getElementById((k+1)+""+j).style.backgroundColor;
					document.getElementById((k+1)+""+j).innerHTML = "";
					document.getElementById((k+1)+""+j).style.backgroundColor = "blueviolet";
					isMoved = true;
				}
			}
		}
		return false;
	}
	function left() {
		isMoved = false;
		excludeIds = [];
		for(var i=min;i<=max;i++) {
			for(var j=min;j<=max;j++) {
				var id = i+""+j;
				if(document.getElementById(id).innerHTML != "") {
					moveLeft(id);
				}
			}
		}
		if(isMoved == true) {
			update();
		}
		return false;
	}
	function moveLeft(id) {
		if(!id.endsWith(min)) {
			var arr = id.split("");
			var i = parseInt(arr[0]);
			var j = parseInt(arr[1]);
			for(var k=(j-1);k>=min;k--) {
				var nId = i+""+k;
				if(document.getElementById(nId).innerHTML != "") {
					var val = parseInt(document.getElementById(i+""+(k+1)).innerHTML);
					var nVal = parseInt(document.getElementById(nId).innerHTML);
					if(val == nVal) {
						if(excludeIds.indexOf(nId) == -1){
							excludeIds.push(nId);
							document.getElementById(nId).innerHTML = (val+nVal);
							document.getElementById(nId).style.backgroundColor = getColor((val+nVal));
							document.getElementById(i+""+(k+1)).innerHTML = "";
							document.getElementById(i+""+(k+1)).style.backgroundColor = "blueviolet";
							isMoved = true;
							score += (val+nVal);
						}
					}
					break;
				}
				else {
					document.getElementById(nId).innerHTML = document.getElementById(i+""+(k+1)).innerHTML;
					document.getElementById(nId).style.backgroundColor = document.getElementById(i+""+(k+1)).style.backgroundColor;
					document.getElementById(i+""+(k+1)).innerHTML = "";
					document.getElementById(i+""+(k+1)).style.backgroundColor = "blueviolet";
					isMoved = true;
				}
			}
		}
		return false;
	}
	function down() {
		isMoved = false;
		excludeIds = [];
		for(var i=min;i<=max;i++) {
			for(var j=max;j>=min;j--) {
				var id = j+""+i;
				if(document.getElementById(id).innerHTML != "") {
					moveDown(id);
				}
			}
		}
		if(isMoved == true) {
			update();
		}
		return false;
	}
	function moveDown(id) {
		if(!id.startsWith(max)) {
			var arr = id.split("");
			var i = parseInt(arr[0]);
			var j = parseInt(arr[1]);
			for(var k=(i+1);k<=max;k++) {
				var nId = k+""+j;
				if(document.getElementById(nId).innerHTML != "") {
					var val = parseInt(document.getElementById((k-1)+""+j).innerHTML);
					var nVal = parseInt(document.getElementById(nId).innerHTML);
					if(val == nVal) {
						if(excludeIds.indexOf(nId) == -1){
							excludeIds.push(nId);
							document.getElementById(nId).innerHTML = (val+nVal);
							document.getElementById(nId).style.backgroundColor = getColor((val+nVal));
							document.getElementById((k-1)+""+j).innerHTML = "";
							document.getElementById((k-1)+""+j).style.backgroundColor = "blueviolet";
							isMoved = true;
							score += (val+nVal);
						}
					}
					break;
				}
				else {
					document.getElementById(nId).innerHTML = document.getElementById((k-1)+""+j).innerHTML;
					document.getElementById(nId).style.backgroundColor = document.getElementById((k-1)+""+j).style.backgroundColor;
					document.getElementById((k-1)+""+j).innerHTML = "";
					document.getElementById((k-1)+""+j).style.backgroundColor = "blueviolet";
					isMoved = true;
				}
			}
		}
		return false;
	}
	function right() {
		isMoved = false;
		excludeIds = [];
		for(var i=min;i<=max;i++) {
			for(var j=max;j>=min;j--) {
				var id = i+""+j;
				if(document.getElementById(id).innerHTML != "") {
					moveRight(id);
				}
			}
		}
		if(isMoved == true) {
			update();
		}
		return false;
	}
	function moveRight(id) {
		if(!id.endsWith(max)) {
			var arr = id.split("");
			var i = parseInt(arr[0]);
			var j = parseInt(arr[1]);
			for(var k=(j+1);k<=max;k++) {
				var nId = i+""+k;
				if(document.getElementById(nId).innerHTML != "") {
					var val = parseInt(document.getElementById(i+""+(k-1)).innerHTML);
					var nVal = parseInt(document.getElementById(nId).innerHTML);
					if(val == nVal) {
						if(excludeIds.indexOf(nId) == -1){
							excludeIds.push(nId);
							document.getElementById(nId).innerHTML = (val+nVal);
							document.getElementById(nId).style.backgroundColor = getColor((val+nVal));
							document.getElementById(i+""+(k-1)).innerHTML = "";
							document.getElementById(i+""+(k-1)).style.backgroundColor = "blueviolet";
							isMoved = true;
							score += (val+nVal);
						}
					}
					break;
				}
				else {
					document.getElementById(nId).innerHTML = document.getElementById(i+""+(k-1)).innerHTML;
					document.getElementById(nId).style.backgroundColor = document.getElementById(i+""+(k-1)).style.backgroundColor;
					document.getElementById(i+""+(k-1)).innerHTML = "";
					document.getElementById(i+""+(k-1)).style.backgroundColor = "blueviolet";
					isMoved = true;
				}
			}
		}
		return false;
	}
	function update() {		
		//Add new value
		var ids = [];
		for(var i=min;i<=max;i++) {
			for(var j=min;j<=max;j++) {
				var id = i+""+j;
				if(document.getElementById(id).innerHTML == "") {
					ids.push(id);
				}
			}
		}
		var id = ids[Math.floor(Math.random()*ids.length)];
        // 새로 생성되는 박스의 innerHTML
		document.getElementById(id).innerHTML = "3";
		document.getElementById(id).style.backgroundColor = getColor(3);

		//Check if no move space available
		var allFilled = true;
		for(var i=min;i<=max;i++) {
			for(var j=min;j<=max;j++) {
				var id = i+""+j;
				if(document.getElementById(id).innerHTML == "") {
					allFilled = false;
					break;
				}
			}
		}		
		//Update score
		best_score = score;
		document.getElementById("score").innerHTML = score;
		document.getElementById("best_score").innerHTML = best_score;
		if(allFilled) {
			checkGameOver();
		}
	}

	function checkGameOver() {
		var isOver = true;
		for(var j=min;j<=max;j++) {
			for(var i=min;i<=(max-1);i++) {
				//alert(i+" "+j);
				var val = parseInt(document.getElementById(i+""+j).innerHTML);
				var nVal = parseInt(document.getElementById((i+1)+""+j).innerHTML);
				if(val == nVal) {
					isOver = false;
					break;
				}
			}
		}		
		if(isOver == true) {
			for(var i=min;i<=max;i++) {
				for(var j=min;j<=(max-1);j++) {
					//alert(i+" "+j);
					var val = parseInt(document.getElementById(i+""+j).innerHTML);
					var nVal = parseInt(document.getElementById(i+""+(j+1)).innerHTML);
					if(val == nVal) {
						isOver = false;
						break;
					}
				}
			}
		}
		if(isOver) {
			alert("Game over!");
		}
		return false;
	}
	function getColor(val)
	{
		// var color = "#ffffff";
        switch(val) {
			case 3:		color = "#000000"; break;
			case 6:		color = "#FF3366"; break;
			case 12:	color = "#FFCC00"; break;
			case 24:	color = "#CCCC33"; break;
			case 48:	color = "#0099FF"; break;
			case 96:	color = "#0000FF"; break;
			case 192:	color = "#000066"; break;
			case 384:	color = "#CCCCFF"; break;
			case 768:	color = "#9966FF"; break;
			case 1536:	color = "#CC66FF"; break;
			case 3072:	color = "#6600CC"; break;
			default:	color = "#FF66FF";
		}
		return color;
	}
	if ( typeof String.prototype.startsWith != 'function' ) {
	  String.prototype.startsWith = function( str ) {
		return this.substring( 0, str.length ) === str;
	  }
	};
	if ( typeof String.prototype.endsWith != 'function' ) {
	  String.prototype.endsWith = function( str ) {
		return this.substring( this.length - str.length, this.length ) === str;
	  }
	};
	document.onkeydown = function(e) {
		e.preventDefault();//to prevent scroll of screen
		switch (e.keyCode) {
			case 37:
				left();
				break;
			case 38:
				up();
				break;
			case 39:
				right();
				break;
			case 40:
				down();
				break;
		}
	};
	//calling load method
	load();
  //-->
  </script>
 </body>
</html>
```

[netlify](https://elegant-salamander-0e65ca.netlify.app)
