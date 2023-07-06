
    ldrImgTime0 = timeit( @() testReadWrite("HDRim/[24]-14.hdr"));
    ldrImgTime1 = timeit( @() testReadWrite("HDRim/[24]-14.hdr"));
    ldrImgTime2 = timeit( @() testReadWrite("HDRim/[24]-14.hdr"));
    ldrImgTime3 = timeit( @() testReadWrite("HDRim/[24]-14.hdr"));
    ldrImgTime4 = timeit( @() testReadWrite("HDRim/[24]-14.hdr"));
    ldrImgTime5 = timeit( @() testReadWrite("HDRim/[24]-14.hdr"));
    ldrImgTime6 = timeit( @() testReadWrite("HDRim/[24]-14.hdr"));
    ldrImgTime7 = timeit( @() testReadWrite("HDRim/[24]-14.hdr"));
    ldrImgTime8 = timeit( @() testReadWrite("HDRim/[24]-14.hdr"));
    ldrImgTime9 = timeit( @() testReadWrite("HDRim/[24]-14.hdr"));
   

function testReadWrite(filePath)
    hdrImg = double(hdrread(filePath));
    ldrImg = DCA_TMO(hdrImg);
    imwrite(uint8(ldrImg), ['LDRim\', 'something', '.png']);
end