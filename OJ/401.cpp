/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-18 15:39:52
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-18 15:40:21
 */
#include<iostream>
#include<queue>
using namespace std;

int sx, sy;
int dir[12][2] = {{1, 2}, {2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-2, 1}, {-1, -2}, {-2, -1}, {2, 2}, {2, -2}, {-2, 2}, {-2, -2}};

struct node{
    int x, y, step;
};