    hdrImg = double(hdrread("HDRim/mpi_office.hdr"));
    ldrImgTime0 = timeit( @() DCA_TMO(hdrImg));
    ldrImgTime1 = timeit( @() DCA_TMO(hdrImg));
    ldrImgTime2 = timeit( @() DCA_TMO(hdrImg));
    ldrImgTime3 = timeit( @() DCA_TMO(hdrImg));
    ldrImgTime4 = timeit( @() DCA_TMO(hdrImg));
    ldrImgTime5 = timeit( @() DCA_TMO(hdrImg));
    ldrImgTime6 = timeit( @() DCA_TMO(hdrImg));
    ldrImgTime7 = timeit( @() DCA_TMO(hdrImg));
    ldrImgTime8 = timeit( @() DCA_TMO(hdrImg));
    ldrImgTime9 = timeit( @() DCA_TMO(hdrImg));
    ldrImg = DCA_TMO(hdrImg);
    
     imwrite(uint8(ldrImg), ['LDRim\', 'something', '.png']);
%     imshow(uint8(ldrImg));
