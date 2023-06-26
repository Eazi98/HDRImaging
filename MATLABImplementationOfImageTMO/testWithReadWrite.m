
    ldrImgTime0 = timeit( @() testReadWrite("HDRim/moto1080.hdr"));
    ldrImgTime1 = timeit( @() testReadWrite("HDRim/moto1080.hdr"));
    ldrImgTime2 = timeit( @() testReadWrite("HDRim/moto1080.hdr"));
    ldrImgTime3 = timeit( @() testReadWrite("HDRim/moto1080.hdr"));
    ldrImgTime4 = timeit( @() testReadWrite("HDRim/moto1080.hdr"));
    ldrImgTime5 = timeit( @() testReadWrite("HDRim/moto1080.hdr"));
    ldrImgTime6 = timeit( @() testReadWrite("HDRim/moto1080.hdr"));
    ldrImgTime7 = timeit( @() testReadWrite("HDRim/moto1080.hdr"));
    ldrImgTime8 = timeit( @() testReadWrite("HDRim/moto1080.hdr"));
    ldrImgTime9 = timeit( @() testReadWrite("HDRim/moto1080.hdr"));
   

function testReadWrite(filePath)
    hdrImg = double(hdrread(filePath));
    ldrImg = DCA_TMO(hdrImg);
    imwrite(uint8(ldrImg), ['LDRim\', 'something', '.png']);
end