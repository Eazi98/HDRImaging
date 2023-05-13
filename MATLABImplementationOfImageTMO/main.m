    hdrImg = double(hdrread("[24]-14.hdr"));
    f = @() DCA_TMO(hdrImg);
    ldrImgTime = timeit(f);
    ldrImg = DCA_TMO(hdrImg);
    imwrite(uint8(ldrImg), ['LDRim\', 'something', '.png']);
    imshow(uint8(ldrImg));
