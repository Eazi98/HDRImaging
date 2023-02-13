    hdrImg = double(hdrread("moto.hdr"));
    ldrImg = DCA_TMO(hdrImg);
    imwrite(uint8(ldrImg), ['LDRim\', 'something', '.png'])
    imshow(uint8(ldrImg))
