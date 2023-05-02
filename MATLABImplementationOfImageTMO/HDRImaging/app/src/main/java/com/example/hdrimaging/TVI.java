package com.example.hdrimaging;

import java.util.ArrayList;

public class TVI {

    public TVI() {
    }

    public double tvi(double[] intensity) {
        double[] threshold= new double[intensity.length];
        ArrayList<Integer> idx = new ArrayList<>();
        idx = find(intensity, 0 ,4,-3.94,0);
        for (int i = 0; i < idx.size(); i++) {
            {
                threshold[idx.get(i)] = -2.86;
            }
        }
        idx = find(intensity,3,0,-3.94,-1.44);
        for (int i = 0; i < idx.size(); i++) {
            {
                double value =(0.405 * intensity[idx.get(i)] + 1.6);
                threshold[idx.get(i)] = Math.pow(value,2.18) - 2.86;
            }
        }

        idx = find(intensity,3,0,-1.44,-0.0184);
        for (int i = 0; i < idx.size(); i++) {
            {
                threshold[idx.get(i)] = intensity[idx.get(i)] - 0.395;
            }
        }

        idx = find(intensity, 3,0,-0.0184,1.9);
        for (int i = 0; i < idx.size(); i++) {
            {
                double value =0.249 * intensity[idx.get(i)] + 0.65;
                threshold[idx.get(i)] = Math.pow(value,2.7) - 0.72;
            }
        }

        idx = find(intensity,3,4, 1.9,0);
        for (int i = 0; i < idx.size(); i++) {
            {
                threshold[idx.get(i)] = intensity[idx.get(i)] - 1.255;
            }
        }


        for (int i = 0; i < threshold.length; i++) {
            {
                threshold[i] = threshold[i] - 0.95;
            }
        }
        return threshold[0];
    }
    private ArrayList<Integer> find(double[] intensity,double check1,double check2, double value1,double value2) {
        // 0 < , 1 >, 2 <=, 3 >=, 4 nulll
        ArrayList<Integer> indexes = new ArrayList<>();
        for (int i = 0; i < intensity.length; i++) {
            if (check1 == 0 && check2 == 4) {
                if (intensity[i] < value1) {
                    indexes.add(i);
                }
            }
            if (check1 == 3 && check2 == 0) {
                if (intensity[i] >= value1 && intensity[i] < value2) {
                    indexes.add(i);
                }
            }
            if (check1 == 3 && check2 == 4) {
                if (intensity[i] >= value1) {
                    indexes.add(i);
                }
            }
        }
        return indexes;
    }
}
