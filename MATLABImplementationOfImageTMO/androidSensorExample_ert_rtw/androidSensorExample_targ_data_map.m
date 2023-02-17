    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (m3wcipx4am)
        ;%
            section.nData     = 43;
            section.data(43)  = dumData; %prealloc

                    ;% m3wcipx4am.b42_Gain
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% m3wcipx4am.b41_Gain
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% m3wcipx4am.b40_Gain
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% m3wcipx4am.b39_Gain
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% m3wcipx4am.b38_Gain
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% m3wcipx4am.b37_Gain
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% m3wcipx4am.b36_Gain
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% m3wcipx4am.b35_Gain
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% m3wcipx4am.b34_Gain
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% m3wcipx4am.b33_Gain
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% m3wcipx4am.b32_Gain
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% m3wcipx4am.b31_Gain
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% m3wcipx4am.b30_Gain
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% m3wcipx4am.b29_Gain
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% m3wcipx4am.b28_Gain
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% m3wcipx4am.b27_Gain
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% m3wcipx4am.b26_Gain
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% m3wcipx4am.b25_Gain
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% m3wcipx4am.b24_Gain
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

                    ;% m3wcipx4am.b23_Gain
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 19;

                    ;% m3wcipx4am.b22_Gain
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 20;

                    ;% m3wcipx4am.b21_Gain
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 21;

                    ;% m3wcipx4am.b20_Gain
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 22;

                    ;% m3wcipx4am.b19_Gain
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 23;

                    ;% m3wcipx4am.b18_Gain
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 24;

                    ;% m3wcipx4am.b17_Gain
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 25;

                    ;% m3wcipx4am.b16_Gain
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 26;

                    ;% m3wcipx4am.b15_Gain
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 27;

                    ;% m3wcipx4am.b14_Gain
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 28;

                    ;% m3wcipx4am.b13_Gain
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 29;

                    ;% m3wcipx4am.b12_Gain
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 30;

                    ;% m3wcipx4am.b11_Gain
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 31;

                    ;% m3wcipx4am.b10_Gain
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 32;

                    ;% m3wcipx4am.b9_Gain
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 33;

                    ;% m3wcipx4am.b8_Gain
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 34;

                    ;% m3wcipx4am.b7_Gain
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 35;

                    ;% m3wcipx4am.b6_Gain
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 36;

                    ;% m3wcipx4am.b5_Gain
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 37;

                    ;% m3wcipx4am.b4_Gain
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 38;

                    ;% m3wcipx4am.b3_Gain
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 39;

                    ;% m3wcipx4am.b2_Gain
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 40;

                    ;% m3wcipx4am.b1_Gain
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 41;

                    ;% m3wcipx4am.b43_Gain
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 42;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 43;
            section.data(43)  = dumData; %prealloc

                    ;% m3wcipx4am.BodyDelay42_InitialCondition
                    section.data(1).logicalSrcIdx = 43;
                    section.data(1).dtTransOffset = 0;

                    ;% m3wcipx4am.BodyDelay41_InitialCondition
                    section.data(2).logicalSrcIdx = 44;
                    section.data(2).dtTransOffset = 1;

                    ;% m3wcipx4am.BodyDelay40_InitialCondition
                    section.data(3).logicalSrcIdx = 45;
                    section.data(3).dtTransOffset = 2;

                    ;% m3wcipx4am.BodyDelay39_InitialCondition
                    section.data(4).logicalSrcIdx = 46;
                    section.data(4).dtTransOffset = 3;

                    ;% m3wcipx4am.BodyDelay38_InitialCondition
                    section.data(5).logicalSrcIdx = 47;
                    section.data(5).dtTransOffset = 4;

                    ;% m3wcipx4am.BodyDelay37_InitialCondition
                    section.data(6).logicalSrcIdx = 48;
                    section.data(6).dtTransOffset = 5;

                    ;% m3wcipx4am.BodyDelay36_InitialCondition
                    section.data(7).logicalSrcIdx = 49;
                    section.data(7).dtTransOffset = 6;

                    ;% m3wcipx4am.BodyDelay35_InitialCondition
                    section.data(8).logicalSrcIdx = 50;
                    section.data(8).dtTransOffset = 7;

                    ;% m3wcipx4am.BodyDelay34_InitialCondition
                    section.data(9).logicalSrcIdx = 51;
                    section.data(9).dtTransOffset = 8;

                    ;% m3wcipx4am.BodyDelay33_InitialCondition
                    section.data(10).logicalSrcIdx = 52;
                    section.data(10).dtTransOffset = 9;

                    ;% m3wcipx4am.BodyDelay32_InitialCondition
                    section.data(11).logicalSrcIdx = 53;
                    section.data(11).dtTransOffset = 10;

                    ;% m3wcipx4am.BodyDelay31_InitialCondition
                    section.data(12).logicalSrcIdx = 54;
                    section.data(12).dtTransOffset = 11;

                    ;% m3wcipx4am.BodyDelay30_InitialCondition
                    section.data(13).logicalSrcIdx = 55;
                    section.data(13).dtTransOffset = 12;

                    ;% m3wcipx4am.BodyDelay29_InitialCondition
                    section.data(14).logicalSrcIdx = 56;
                    section.data(14).dtTransOffset = 13;

                    ;% m3wcipx4am.BodyDelay28_InitialCondition
                    section.data(15).logicalSrcIdx = 57;
                    section.data(15).dtTransOffset = 14;

                    ;% m3wcipx4am.BodyDelay27_InitialCondition
                    section.data(16).logicalSrcIdx = 58;
                    section.data(16).dtTransOffset = 15;

                    ;% m3wcipx4am.BodyDelay26_InitialCondition
                    section.data(17).logicalSrcIdx = 59;
                    section.data(17).dtTransOffset = 16;

                    ;% m3wcipx4am.BodyDelay25_InitialCondition
                    section.data(18).logicalSrcIdx = 60;
                    section.data(18).dtTransOffset = 17;

                    ;% m3wcipx4am.BodyDelay24_InitialCondition
                    section.data(19).logicalSrcIdx = 61;
                    section.data(19).dtTransOffset = 18;

                    ;% m3wcipx4am.BodyDelay23_InitialCondition
                    section.data(20).logicalSrcIdx = 62;
                    section.data(20).dtTransOffset = 19;

                    ;% m3wcipx4am.BodyDelay22_InitialCondition
                    section.data(21).logicalSrcIdx = 63;
                    section.data(21).dtTransOffset = 20;

                    ;% m3wcipx4am.BodyDelay21_InitialCondition
                    section.data(22).logicalSrcIdx = 64;
                    section.data(22).dtTransOffset = 21;

                    ;% m3wcipx4am.BodyDelay20_InitialCondition
                    section.data(23).logicalSrcIdx = 65;
                    section.data(23).dtTransOffset = 22;

                    ;% m3wcipx4am.BodyDelay19_InitialCondition
                    section.data(24).logicalSrcIdx = 66;
                    section.data(24).dtTransOffset = 23;

                    ;% m3wcipx4am.BodyDelay18_InitialCondition
                    section.data(25).logicalSrcIdx = 67;
                    section.data(25).dtTransOffset = 24;

                    ;% m3wcipx4am.BodyDelay17_InitialCondition
                    section.data(26).logicalSrcIdx = 68;
                    section.data(26).dtTransOffset = 25;

                    ;% m3wcipx4am.BodyDelay16_InitialCondition
                    section.data(27).logicalSrcIdx = 69;
                    section.data(27).dtTransOffset = 26;

                    ;% m3wcipx4am.BodyDelay15_InitialCondition
                    section.data(28).logicalSrcIdx = 70;
                    section.data(28).dtTransOffset = 27;

                    ;% m3wcipx4am.BodyDelay14_InitialCondition
                    section.data(29).logicalSrcIdx = 71;
                    section.data(29).dtTransOffset = 28;

                    ;% m3wcipx4am.BodyDelay13_InitialCondition
                    section.data(30).logicalSrcIdx = 72;
                    section.data(30).dtTransOffset = 29;

                    ;% m3wcipx4am.BodyDelay12_InitialCondition
                    section.data(31).logicalSrcIdx = 73;
                    section.data(31).dtTransOffset = 30;

                    ;% m3wcipx4am.BodyDelay11_InitialCondition
                    section.data(32).logicalSrcIdx = 74;
                    section.data(32).dtTransOffset = 31;

                    ;% m3wcipx4am.BodyDelay10_InitialCondition
                    section.data(33).logicalSrcIdx = 75;
                    section.data(33).dtTransOffset = 32;

                    ;% m3wcipx4am.BodyDelay9_InitialCondition
                    section.data(34).logicalSrcIdx = 76;
                    section.data(34).dtTransOffset = 33;

                    ;% m3wcipx4am.BodyDelay8_InitialCondition
                    section.data(35).logicalSrcIdx = 77;
                    section.data(35).dtTransOffset = 34;

                    ;% m3wcipx4am.BodyDelay7_InitialCondition
                    section.data(36).logicalSrcIdx = 78;
                    section.data(36).dtTransOffset = 35;

                    ;% m3wcipx4am.BodyDelay6_InitialCondition
                    section.data(37).logicalSrcIdx = 79;
                    section.data(37).dtTransOffset = 36;

                    ;% m3wcipx4am.BodyDelay5_InitialCondition
                    section.data(38).logicalSrcIdx = 80;
                    section.data(38).dtTransOffset = 37;

                    ;% m3wcipx4am.BodyDelay4_InitialCondition
                    section.data(39).logicalSrcIdx = 81;
                    section.data(39).dtTransOffset = 38;

                    ;% m3wcipx4am.BodyDelay3_InitialCondition
                    section.data(40).logicalSrcIdx = 82;
                    section.data(40).dtTransOffset = 39;

                    ;% m3wcipx4am.BodyDelay2_InitialCondition
                    section.data(41).logicalSrcIdx = 83;
                    section.data(41).dtTransOffset = 40;

                    ;% m3wcipx4am.BodyDelay43_InitialCondition
                    section.data(42).logicalSrcIdx = 84;
                    section.data(42).dtTransOffset = 41;

                    ;% m3wcipx4am.Gain_Gain
                    section.data(43).logicalSrcIdx = 85;
                    section.data(43).dtTransOffset = 42;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 0;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (llpy3v0cz3s)
        ;%

            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 4;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (bnf25bqflp5)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% bnf25bqflp5.bb4refxuny
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 42;
            section.data(42)  = dumData; %prealloc

                    ;% bnf25bqflp5.o4v4nmvn3u
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% bnf25bqflp5.c2351buhnn
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 3;

                    ;% bnf25bqflp5.c2cfcdgbmg
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 6;

                    ;% bnf25bqflp5.f0gwg3juzq
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 9;

                    ;% bnf25bqflp5.ib5201g4ke
                    section.data(5).logicalSrcIdx = 5;
                    section.data(5).dtTransOffset = 12;

                    ;% bnf25bqflp5.nbbxcxhctw
                    section.data(6).logicalSrcIdx = 6;
                    section.data(6).dtTransOffset = 15;

                    ;% bnf25bqflp5.p4vbkue35t
                    section.data(7).logicalSrcIdx = 7;
                    section.data(7).dtTransOffset = 18;

                    ;% bnf25bqflp5.j1gbzr12g2
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 21;

                    ;% bnf25bqflp5.njn4a0oaxh
                    section.data(9).logicalSrcIdx = 9;
                    section.data(9).dtTransOffset = 24;

                    ;% bnf25bqflp5.ehewprdej1
                    section.data(10).logicalSrcIdx = 10;
                    section.data(10).dtTransOffset = 27;

                    ;% bnf25bqflp5.ceqekm5bks
                    section.data(11).logicalSrcIdx = 11;
                    section.data(11).dtTransOffset = 30;

                    ;% bnf25bqflp5.f43ssdxia0
                    section.data(12).logicalSrcIdx = 12;
                    section.data(12).dtTransOffset = 33;

                    ;% bnf25bqflp5.fam1sk0fja
                    section.data(13).logicalSrcIdx = 13;
                    section.data(13).dtTransOffset = 36;

                    ;% bnf25bqflp5.lo5iqolvhv
                    section.data(14).logicalSrcIdx = 14;
                    section.data(14).dtTransOffset = 39;

                    ;% bnf25bqflp5.gshzek2dqv
                    section.data(15).logicalSrcIdx = 15;
                    section.data(15).dtTransOffset = 42;

                    ;% bnf25bqflp5.ehlkac3xdj
                    section.data(16).logicalSrcIdx = 16;
                    section.data(16).dtTransOffset = 45;

                    ;% bnf25bqflp5.bybogcsaxa
                    section.data(17).logicalSrcIdx = 17;
                    section.data(17).dtTransOffset = 48;

                    ;% bnf25bqflp5.g1r4kw1wyh
                    section.data(18).logicalSrcIdx = 18;
                    section.data(18).dtTransOffset = 51;

                    ;% bnf25bqflp5.bjmrz01wvt
                    section.data(19).logicalSrcIdx = 19;
                    section.data(19).dtTransOffset = 54;

                    ;% bnf25bqflp5.bbimmqhsy4
                    section.data(20).logicalSrcIdx = 20;
                    section.data(20).dtTransOffset = 57;

                    ;% bnf25bqflp5.hqbfuxg5bu
                    section.data(21).logicalSrcIdx = 21;
                    section.data(21).dtTransOffset = 60;

                    ;% bnf25bqflp5.cbmr5ybudp
                    section.data(22).logicalSrcIdx = 22;
                    section.data(22).dtTransOffset = 63;

                    ;% bnf25bqflp5.m2j5cuo4cp
                    section.data(23).logicalSrcIdx = 23;
                    section.data(23).dtTransOffset = 66;

                    ;% bnf25bqflp5.i0wlv3cnks
                    section.data(24).logicalSrcIdx = 24;
                    section.data(24).dtTransOffset = 69;

                    ;% bnf25bqflp5.hxcihk00xk
                    section.data(25).logicalSrcIdx = 25;
                    section.data(25).dtTransOffset = 72;

                    ;% bnf25bqflp5.dinln0cljw
                    section.data(26).logicalSrcIdx = 26;
                    section.data(26).dtTransOffset = 75;

                    ;% bnf25bqflp5.onqv0cokzz
                    section.data(27).logicalSrcIdx = 27;
                    section.data(27).dtTransOffset = 78;

                    ;% bnf25bqflp5.n5heh112e0
                    section.data(28).logicalSrcIdx = 28;
                    section.data(28).dtTransOffset = 81;

                    ;% bnf25bqflp5.em0u5ar2w0
                    section.data(29).logicalSrcIdx = 29;
                    section.data(29).dtTransOffset = 84;

                    ;% bnf25bqflp5.neiwzzf3d2
                    section.data(30).logicalSrcIdx = 30;
                    section.data(30).dtTransOffset = 87;

                    ;% bnf25bqflp5.mzldi3gwbf
                    section.data(31).logicalSrcIdx = 31;
                    section.data(31).dtTransOffset = 90;

                    ;% bnf25bqflp5.lcswcl24dd
                    section.data(32).logicalSrcIdx = 32;
                    section.data(32).dtTransOffset = 93;

                    ;% bnf25bqflp5.ohdifnqgph
                    section.data(33).logicalSrcIdx = 33;
                    section.data(33).dtTransOffset = 96;

                    ;% bnf25bqflp5.npkhteuddn
                    section.data(34).logicalSrcIdx = 34;
                    section.data(34).dtTransOffset = 99;

                    ;% bnf25bqflp5.mc01m1iiyp
                    section.data(35).logicalSrcIdx = 35;
                    section.data(35).dtTransOffset = 102;

                    ;% bnf25bqflp5.kc2onrurfq
                    section.data(36).logicalSrcIdx = 36;
                    section.data(36).dtTransOffset = 105;

                    ;% bnf25bqflp5.j0pawa4ufn
                    section.data(37).logicalSrcIdx = 37;
                    section.data(37).dtTransOffset = 108;

                    ;% bnf25bqflp5.gtqhyhztvq
                    section.data(38).logicalSrcIdx = 38;
                    section.data(38).dtTransOffset = 111;

                    ;% bnf25bqflp5.krg5teap1w
                    section.data(39).logicalSrcIdx = 39;
                    section.data(39).dtTransOffset = 114;

                    ;% bnf25bqflp5.pdkumqgqyi
                    section.data(40).logicalSrcIdx = 40;
                    section.data(40).dtTransOffset = 117;

                    ;% bnf25bqflp5.k0h2hqja5u
                    section.data(41).logicalSrcIdx = 41;
                    section.data(41).dtTransOffset = 120;

                    ;% bnf25bqflp5.afblsn3kpj
                    section.data(42).logicalSrcIdx = 42;
                    section.data(42).dtTransOffset = 123;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% bnf25bqflp5.nkk1pmzl4z
                    section.data(1).logicalSrcIdx = 43;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% bnf25bqflp5.kxmxusvbjz
                    section.data(1).logicalSrcIdx = 44;
                    section.data(1).dtTransOffset = 0;

                    ;% bnf25bqflp5.o3zxfzvoah
                    section.data(2).logicalSrcIdx = 45;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 2548169320;
    targMap.checksum1 = 1166250922;
    targMap.checksum2 = 935248969;
    targMap.checksum3 = 2403459094;

