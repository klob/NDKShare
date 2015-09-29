package com.diandi.klob.listviewshare;

import java.util.List;


/**
 * *******************************************************************************
 * *********    Author : klob(kloblic@gmail.com) .
 * *********    Date : 2015-09-25  .
 * *********    Time : 11:39 .
 * *********    Version : 1.0
 * *********    Copyright © 2015, klob, All Rights Reserved
 * *******************************************************************************
 */
public interface IBus<T>  {

    //初始化列表
    void initListView();


    //抽象方法，初始化适配器
    void initAdapter();

    //刷新调用的方法
    void onRefresh();

    //抽象方法，加载更多
    void onLoadMore();

    //抽象方法，第一次获取数据
    void initDataList(final boolean isFresh);

    //刷新数据
    void fresh(final boolean isUpdate, final List<T> list);

    //加载更多
    void loadMore();

    void setLoadMorable(boolean loadMorable);

    //预处理数据
     void preProcessData(List<T> list);

     //刷新预处理
     void refreshProcess(final List<T> list);

    //加载更多预测处理
     void loadMoreProcess(final List<T> list);

    //初始化缓存
    void initCache();

    //保存缓存
    void saveCache();


    //设置缓存key
    public void setCacheKey(String key);

    //统计数据量
    void count();


    //停止加载更多
    void refreshLoad();

    //停止刷新
    void refreshPull();

    //取得缓存成功
    void onSuccess(List object);

    //取得缓存失败
    void onFailure(boolean exist);

}
