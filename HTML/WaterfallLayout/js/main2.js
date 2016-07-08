//Jquery实现瀑布布局


$(window).on('load', function() {
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
	$(window).on('scroll', function() {
		if (checkScollSlid) {
			$.each(dataInt.data, function(index, el) {
				$('#main').append("<div class='box'><div class='pic'><img src=" + el.src + "></div></div>");
			});
			waterfall('main', 'box');
		}
	})
});

//判断滑动条是否在需要加载图片的位置
function checkScollSlid() {
	var $lastBox = $('#main').last();
	var lastBoxDis = $lastBox.offset() + Math.floor($lastBox.outerHeight() / 2);
	var hWindow = $(window).height();
	return lastBoxDis > hWindow;
}

//实现瀑布布局
function waterfall(parent, clsName) {
	var $parent = $('#' + parent);
	var $boxs = $parent.find('.' + clsName);
	var boxW = $boxs.eq(0).outerWidth();
	var cols = Math.floor($(window).width() / boxW);
	$parent.width(boxW * cols).css('margin', '0 auto');
	var hArr = [];
	//el是dom元素，不能用jquery方法
	$boxs.each(function(index, el) {
		var height = $(el).outerHeight();
		if (index < cols) {
			hArr.push(height);
		} else {
			var minH = Math.min.apply(null, hArr);
			//内置求元素在数组的高度
			var minIndex = $.inArray(minH, hArr);
			$(el).css({
				'position': 'absolute',
				'top': minH + 'px',
				'left': boxW * minIndex + 'px'
			});
			hArr[minIndex] += height;
		}
		console.log(hArr);
	});
}