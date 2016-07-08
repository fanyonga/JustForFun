$(document).ready(function() {
	$('.input-text').keyup(function(){
		var $this=$(this);
		var searchText=$this.val();
		$.get("http://api.bing.com/qsonhs.aspx?q="+searchText,function(data){
			console.log(data.AS.Results[0].Suggests);
		},'json');
		
		$("#suggest").show().css({
			'position': 'absolute',

		});

	})
})