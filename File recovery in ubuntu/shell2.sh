
filname=0
filtype=0
echo "enter the image file files which you want to recover files"
read filname 
echo "Press 1 to recover PDF files and 2 to recover JPG files and 3 for all"
read filtype

if [ $filtype -eq 1 ]
then 
	
	rm headerpospdf
	rm footerpospdf
	g++ saveheaderpdf.cpp -o headerpdf
	g++ savefooterpdf.cpp -o footerpdf
	g++ recoverpdf.cpp -o rcvrpdf
	./headerpdf $filname
	./footerpdf $filname
	./rcvrpdf $filname
	
	

elif [ $filtype -eq 2 ]
then
	rm headerposjpg
	rm footerposjpg
	g++ saveheaderjpg.cpp -o headerjpg
	g++ savefooterjpg.cpp -o footerjpg
	g++ recoverjpg.cpp -o rcvrjpg
	./headerjpg $filname
	./footerjpg $filname
	./rcvrjpg $filname

	


elif [ $filtype -eq 3 ]
then
	rm headerpospdf
	rm footerpospdf
	g++ saveheaderpdf.cpp -o headerpdf
	g++ savefooterpdf.cpp -o footerpdf
	g++ recoverpdf.cpp -o rcvrpdf
	./headerpdf $filname
	./footerpdf $filname
	./rcvrpdf $filname
	rm headerposjpg
	rm footerposjpg
	g++ saveheaderjpg.cpp -o headerjpg
	g++ savefooterjpg.cpp -o footerjpg
	g++ recoverjpg.cpp -o rcvrjpg
	./headerjpg $filname
	./footerjpg $filname
	./rcvrjpg $filname
	

else
	echo "give filetype 1,2,3 "

fi



