<script>
	
	
	var seed1Count=[];
	var seed2Count=[];
	var countA=0;
	var countB=0;
	var countC=0;
	var countD=0;
	var countE=0;
	var countF=0;
	var countG=0;
	var countH=0;
	var total=0;
    
		$(".groupA").click(function(){
			countA++;
			if(countA<=2)
			{
			$(this).appendTo($(".groupATable1"));
			}
			if(countA==2){
			$(this).appendTo($(".groupATable2"));
			$(".A").slideUp("slow",function(){
			});
			}
			totalCount();
		});
		$(".groupB").click(function(){
			countB++;
			if(countB<=2)
			{
			$(this).appendTo($(".groupBTable1"));
			}
			if(countB==2){
			$(this).appendTo($(".groupBTable2"));
			$(".B").slideUp("slow",function(){
			});
			}
			totalCount();
		});
		$(".groupC").click(function(){
			countC++;
			if(countC<=2)
			{
			$(this).appendTo($(".groupCTable1"));
			}
			if(countC==2){
			$(this).appendTo($(".groupCTable2"));
			$(".C").slideUp("slow",function(){
			});
			}
			totalCount();
		});
		$(".groupD").click(function(){
			countD++;
			if(countD<=2)
			{
			$(this).appendTo($(".groupDTable1"));
			}
			if(countD==2){
			$(this).appendTo($(".groupDTable2"));
			$(".D").slideUp("slow",function(){
			});
			}
			totalCount();
		});
		$(".groupE").click(function(){
			countE++;
			if(countE<=2)
			{
			$(this).appendTo($(".groupETable1"));
			}
			if(countE==2){
			$(this).appendTo($(".groupETable2"));
			$(".E").slideUp("slow",function(){
			});
			}
			totalCount();
		});
		$(".groupF").click(function(){
			countF++;
			if(countF<=2)
			{
			$(this).appendTo($(".groupFTable1"));
			}
			if(countF==2){
			$(this).appendTo($(".groupFTable2"));
			$(".F").slideUp("slow",function(){
			});
			}
			totalCount();
		});
		$(".groupG").click(function(){
			countG++;
			if(countG<=2)
			{
			$(this).appendTo($(".groupGTable1"));
			}
			if(countG==2){
			$(this).appendTo($(".groupGTable2"));
			$(".G").slideUp("slow",function(){
			});
			}
			totalCount();
		});
		$(".groupH").click(function(){
			countH++;
			if(countH==1)
			{
			$(this).appendTo($(".groupHTable1"));
			}
			if(countH==2){
			$(this).appendTo($(".groupHTable2"));
			$(".H").slideUp("slow",function(){
			});	
			}
			totalCount();
		});
	
		//starting other functions
		function totalCount(){
			total=countA+countB+countC+countD+countE+countF+countG+countH;
			if(total==16){
				$(".next").removeAttr('disabled');
				makeSeed1();
				makeSeed2();
			}
		}
		function makeSeed1(){
			$(".table").each(function(){
				var $tds = $(this).find('td');
				var $currText=$tds.eq(0).text();
				seed1Count.push($currText);
			});
		}
		function makeSeed2(){
			$(".table").each(function(){
				var $tds = $(this).find('td');
				var $currText=$tds.eq(1).text();
				seed2Count.push($currText);
			});
		}
		function transferSeeds(){
			$(".groupATable1").appendTo($(".A1"));
			$(".groupATable2").appendTo($(".A2"));
			$(".groupBTable1").appendTo($(".B1"));
			$(".groupBTable2").appendTo($(".B2"));
			$(".groupCTable1").appendTo($(".C1"));
			$(".groupCTable2").appendTo($(".C2"));
			$(".groupDTable1").appendTo($(".D1"));
			$(".groupDTable2").appendTo($(".D2"));
			$(".groupETable1").appendTo($(".E1"));
			$(".groupETable2").appendTo($(".E2"));
			$(".groupFTable1").appendTo($(".F1"));
			$(".groupFTable2").appendTo($(".F2"));
			$(".groupGTable1").appendTo($(".G1"));
			$(".groupGTable2").appendTo($(".G2"));
			$(".groupHTable1").appendTo($(".H1"));
			$(".groupHTable2").appendTo($(".H2"));
		}
		function checkSave(){
			if($(".champion").length > 0){
				$(".save").removeAttr('disabled');
			}
		}
		
	
		$(".next").click(function(){
			transferSeeds();
			$(".initial").slideUp();
			$(".bracket").slideDown();
		});
		
		$(".reset").click(function(){
			window.location.reload();
		});

		var bracketList=[];
		var listClass=[];
		$(".save").click(function(){
			$(".tournamentBracket li").each(function(){
				bracketList.push($(this).text());
				listClass.push($(this).attr('class'));
			});
			localStorage.setItem("bracketList",JSON.stringify(bracketList));
			localStorage.setItem("listClass",JSON.stringify(listClass));
			console.log(bracketList);
			console.log(listClass);
			var bracketName = $("#bracketKey").val();
			localStorage.setItem("idName",JSON.stringify(bracketName));
			var newItem = document.createElement("li");
				newItem.innerHTML = bracketName;
			//alert(bracketName);
			$(".nav-justified>.dropdown .dropdown-menu").append(newItem);
			//$(".container ul").listview("refresh");
			window.location.href='complete.html';
		});
			
		// Funçoes para o duelo de 16 pra quartas de final 
		
		var team1=0;
		var team2=0;
		var team3=0;
		var team4=0;
		var team5=0;
		var team6=0;
		var team7=0;
		var team8=0;
		var team9=0;
		var team10=0;
		var team11=0;
		var team12=0;
		var team13=0;
		var team14=0;
		var team15=0;
		var team16=0;
		//avançado de A1 ana B2
		$(".A1").click(function(){
			team1++;
			$(this).clone().appendTo($(".quarter1")).end();
			$(this).unbind('click');
			$(".B2").unbind('click');
		});
		
		$(".B2").click(function(){
			team2++;
			$(this).clone().appendTo($(".quarter1")).end();
			$(this).unbind('click');
			$(".A1").unbind('click');
		});	
		
		$(".quarter1").click(function(){
			$(this).clone().appendTo($(".semi1")).end();
			$(this).unbind('click');
			$(".quarter2").unbind('click');
		});	
		
		$(".semi1").click(function(){
			$(this).clone().appendTo($(".final1")).end();
			$(this).unbind('click');
			$(".semi2").unbind('click');
		});	
		
		$(".final1").click(function(){
			$(this).clone().appendTo($(".champion")).end();
			$(this).unbind('click');
			$(".final2").unbind('click');
			checkSave();
		});	
		
		//Avançado de C1 a D2
		$(".C1").click(function(){
			team3++;
			$(this).clone().appendTo($(".quarter2")).end();
			$(this).unbind('click');
			$(".D2").unbind('click');
		});
		$(".D2").click(function(){
			team4++;
			$(this).clone().appendTo($(".quarter2")).end();
			$(this).unbind('click');
			$(".C1").unbind('click');
		});
		
		$(".quarter2").click(function(){
			$(this).clone().appendTo($(".semi1")).end();
			$(this).unbind('click');
			$(".quarter1").unbind('click');
		});
		
		//Avançado de E1 a F2
		$(".E1").click(function(){
			team5++;
			$(this).clone().appendTo($(".quarter3")).end();
			$(this).unbind('click');
			$(".F2").unbind('click');
		});
		
		$(".F2").click(function(){
			team6++;
			$(this).clone().appendTo($(".quarter3")).end();
			$(this).unbind('click');
			$(".E1").unbind('click');
		});
		
		$(".quarter3").click(function(){
			$(this).clone().appendTo($(".semi2")).end();
			$(this).unbind('click');
			$(".quarter4").unbind('click');
		});
		
		$(".semi2").click(function(){
			$(this).clone().appendTo($(".final1")).end();
			$(this).unbind('click');
			$(".semi1").unbind('click');
		});
		
		//Avançado de G1 a H2
		$(".G1").click(function(){
			team7++;
			$(this).clone().appendTo($(".quarter4")).end();
			$(this).unbind('click');
			$(".H2").unbind('click');
		});
		
		$(".H2").click(function(){
			team8++;
			$(this).clone().appendTo($(".quarter4")).end();
			$(this).unbind('click');
			$(".G1").unbind('click');
		});
		
		$(".quarter4").click(function(){
			$(this).clone().appendTo($(".semi2")).end();
			$(this).unbind('click');
			$(".quarter3").unbind('click');
		});
		//Avançado de D1 a C2
		$(".D1").click(function(){
			team9++;
			$(this).clone().appendTo($(".quarter5")).end();
			$(this).unbind('click');
			$(".C2").unbind('click');
		});
		
		$(".C2").click(function(){
			team10++;
			$(this).clone().appendTo($(".quarter5")).end();
			$(this).unbind('click');
			$(".D1").unbind('click');
		});
		
		$(".quarter5").click(function(){
			$(this).clone().appendTo($(".semi3")).end();
			$(this).unbind('click');
			$(".quarter6").unbind('click');
		});
		
		$(".semi3").click(function(){
			$(this).clone().appendTo($(".final2")).end();
			$(this).unbind('click');
			$(".semi4").unbind('click');
		});
		
		//Avançado de B1 a A2
		$(".B1").click(function(){
			team11++;
			$(this).clone().appendTo($(".quarter6")).end();
			$(this).unbind('click');
			$(".A2").unbind('click');
		});
		
		$(".A2").click(function(){
			team12++;
			$(this).clone().appendTo($(".quarter6")).end();
			$(this).unbind('click');
			$(".B1").unbind('click');
		});
		
		$(".quarter6").click(function(){
			$(this).clone().appendTo($(".semi3")).end();
			$(this).unbind('click');
			$(".quarter5").unbind('click');
		});
		
		//Avançado de F1 a E2
		$(".F1").click(function(){
			team13++;
			$(this).clone().appendTo($(".quarter7")).end();
			$(this).unbind('click');
			$(".E2").unbind('click');
		});
		
		$(".E2").click(function(){
			team14++;
			$(this).clone().appendTo($(".quarter7")).end();
			$(this).unbind('click');
			$(".F1").unbind('click');
		});
		
		$(".quarter7").click(function(){
			$(this).clone().appendTo($(".semi4")).end();
			$(this).unbind('click');
			$(".quarter8").unbind('click');
		});
		
		$(".semi4").click(function(){
			$(this).clone().appendTo($(".final2")).end();
			$(this).unbind('click');
			$(".semi3").unbind('click');
		});
		$(".final2").click(function(){
			$(this).clone().appendTo($(".champion")).end();
			$(this).unbind('click');
			$(".final1").unbind('click');
			checkSave();
		});	
		
		//Avançado de H1 a G2
		$(".H1").click(function(){
			team15++;
			$(this).clone().appendTo($(".quarter8")).end();
			$(this).unbind('click');
			$(".G2").unbind('click');
		});
		
		$(".G2").click(function(){
			team16++;
			$(this).clone().appendTo($(".quarter8")).end();
			$(this).unbind('click');
			$(".H1").unbind('click');
		});
		
		$(".quarter8").click(function(){
			$(this).clone().appendTo($(".semi4")).end();
			$(this).unbind('click');
			$(".quarter7").unbind('click');
		});
	</script>
	