
    ldrImgTime0 = timeit( @() testReadWrite("HDRim/moto2350x1322.hdr"));
    ldrImgTime1 = timeit( @() testReadWrite("HDRim/moto2350x1322.hdr"));
    ldrImgTime2 = timeit( @() testReadWrite("HDRim/moto2350x1322.hdr"));
    ldrImgTime3 = timeit( @() testReadWrite("HDRim/moto2350x1322.hdr"));
    ldrImgTime4 = timeit( @() testReadWrite("HDRim/moto2350x1322.hdr"));
    ldrImgTime5 = timeit( @() testReadWrite("HDRim/moto2350x1322.hdr"));
    ldrImgTime6 = timeit( @() testReadWrite("HDRim/moto2350x1322.hdr"));
    ldrImgTime7 = timeit( @() testReadWrite("HDRim/moto2350x1322.hdr"));
    ldrImgTime8 = timeit( @() testReadWrite("HDRim/moto2350x1322.hdr"));
    ldrImgTime9 = timeit( @() testReadWrite("HDRim/moto2350x1322.hdr"));
   

function testReadWrite(filePath)
    hdrImg = double(hdrread(filePath));
    ldrImg = DCA_TMO(hdrImg);
    imwrite(uint8(ldrImg), ['LDRim\', 'something', '.png']);
end