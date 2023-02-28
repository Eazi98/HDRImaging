    hdrImg = hdrread("[24]-14.hdr");
    ldrImg = DCA_TMO(hdrImg);
    imwrite(uint8(ldrImg), ['LDRim\', 'something', '.png'])
    imshow(uint8(ldrImg))
