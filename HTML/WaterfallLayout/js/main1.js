//纯javascript实现瀑布流


window.onload = function() {
	waterfall('main', 'box');
	//模拟从后台获得家在图片的数据
	var dataInt = {
		'data': [{
			"src": "images/2.jpg"
		}, {
			"src": "images/2.jpg"
		}, {
			"src": "images/2.jpg"
		}, {
			"src": "images/2.jpg"
		}, {
			"src": "images/2.jpg"
		}, {
			"src": "images/2.jpg"
		}, {
			"src": "images/2.jpg"
		}, {
			"src": "images/2.jpg"
		}, {
			"src": "images/2.jpg"
		}, {
			"src": "images/2.jpg"
		}, {
			"src": "images/2.jpg"
		}, {
			"src": "images/2.jpg"
		}, {
			"src": "images/2.jpg"
		}, {
			"src": "images/2.jpg"
		}, {
			"src": "images/2.jpg"
		}, {
			"src": "images/2.jpg"
		}]
	}
	window.onscroll = function() {
		if (checkScollSlid) {
			console.log("加载图片");
			for (var i = 0; i < dataInt.data.length; i++) {
				var o_parent = document.getElementById('main');
				var box = document.createElement('div');
				box.className = 'box';
				o_parent.appendChild(box);

				var pic = document.createElement('div');
				pic.className = 'pic';
				box.appendChild(pic);

				var img = document.createElement('img');
				img.src = dataInt.data[i].src;
				pic.appendChild(img);
			}
			waterfall('main', 'box');
		}
	}
}

//判断滑动条是否在需要加载图片的位置
function checkScollSlid() {
	var o_parent = document.getElementById('main');
	var o_boxs = getByClass(o_parent, 'box');
	var lastBoxH = o_boxs[o_boxs.length - 1].offsetTop + Math.floor(o_boxs[o_boxs.length - 1].offsetHeight / 2);
	var scrollTop = document.documentElement.scrollTop || document.body.scrollTop;
	// console.log(scrollTop);
	var height = document.body.clientHeight || document.documentElement.clientHeight;
	// console.log(height);
	return lastBoxH < scrollTop + height;
}

//实现瀑布布局
function waterfall(parent, clsName) {
	//获得main元素下所有class为box的元素
	var o_parent = document.getElementById(parent);
	var o_boxs = getByClass(o_parent, clsName);
	//计算每行图片的个数
	var boxW = o_boxs[0].offsetWidth;
	var imgCol = Math.floor(document.documentElement.clientWidth / boxW);
	//设置main元素的宽度，并使其居中
	o_parent.style.cssText = "width:" + imgCol * boxW + "px;margin:0 auto";
	var hArr = []; //存储一列图片的高度
	for (var i = 0; i < o_boxs.length; i++) {
		if (i < imgCol) { //加入初始一列的高度
			hArr.push(o_boxs[i].offsetHeight);
		} else { //依次将剩下的图片添加到高度最小的元素下，并改变相应的高度
			var minH = Math.min.apply(null, hArr);
			var minIndex = getIndex(hArr, minH);
			o_boxs[i].style.position = "absolute";
			o_boxs[i].style.top = minH + "px";
			//o_boxs[i].style.left=boxW*minIndex+"px";
			o_boxs[i].style.left = o_boxs[minIndex].offsetLeft + "px";
			hArr[minIndex] += o_boxs[i].offsetHeight;
		}
	}
}

//获得parent下所有class为clsName的元素
function getByClass(parent, clsName) {
	var boxArray = new Array();
	var elements = parent.getElementsByTagName('*');
	for (var i = 0; i < elements.length; i++) {
		if (elements[i].className == clsName)
			boxArray.push(elements[i]);
	}
	return boxArray;
}

//根据元素内容并返回在数组的索引
function getIndex(arr, height) {
	for (var i = 0; i < arr.length; i++) {
		if (arr[i] == height) {
			return i;
		}
	}
}