﻿/** @file nim_http.h
  * @brief NIM SDK提供的http接口 
  * @copyright (c) 2015, NetEase Inc. All rights reserved
  * @author Oleg
  * @date 2015/2/1
  */
#ifndef NIM_SDK_DLL_API_NIM_HTTP_H_
#define NIM_SDK_DLL_API_NIM_HTTP_H_

#include "nim_sdk_dll.h"
#include "nim_http_def.h"

#ifdef __cplusplus
extern"C"
{
#endif

/** @fn void nim_http_reg_dl_cb(nim_http_dl_cb_func cb, const void *user_data)
  * 注册下载回调，通过注册回调获得http下载结果通知，刷新资源
  * @param[in] cb 下载的回调函数， nim_http_dl_cb_func回调函数定义见nim_http_def.h
  * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
  * @return void 无返回值
  */
NIM_SDK_DLL_API void nim_http_reg_dl_cb(nim_http_dl_cb_func cb, const void *user_data);

/** @fn void nim_http_fetch_media(const char *json_msg, nim_http_dl_cb_func res_cb, const void *res_user_data, nim_http_dl_prg_cb_func prg_cb, const void *prg_user_data)
  * 获取资源
  * @param[in] json_msg 消息体json string (Keys SEE MORE `nim_talk_def.h` 『消息结构 Json Keys』)
  * @param[in] res_cb 下载的回调函数， nim_http_dl_cb_func回调函数定义见nim_http_def.h
  * @param[in] res_user_data APP的自定义用户数据，SDK只负责传回给回调函数res_cb，不做任何处理！
  * @param[in] prg_cb 下载进度的回调函数， nim_http_dl_prg_cb_func回调函数定义见nim_http_def.h
  * @param[in] prg_user_data APP的自定义用户数据，SDK只负责传回给回调函数prg_cb，不做任何处理！
  * @return void 无返回值
  */
NIM_SDK_DLL_API void nim_http_fetch_media(const char *json_msg, nim_http_dl_cb_func res_cb, const void *res_user_data, nim_http_dl_prg_cb_func prg_cb, const void *prg_user_data);

/** @fn void nim_http_stop_fetch_media(const char *json_msg)
  * 停止获取资源（目前仅对文件消息类型有效）
  * @param[in] json_msg 消息体json string (Keys SEE MORE `nim_talk_def.h` 『消息结构 Json Keys』)
  * @return void 无返回值
  */
NIM_SDK_DLL_API void nim_http_stop_fetch_media(const char *json_msg);

/** @fn void nim_http_up(const char *local_file, nim_http_up_cb_func res_cb, const void *res_user_data, nim_http_up_prg_cb_func prg_cb, const void *prg_user_data)
  * 上传资源
  * @param[in] local_file 本地文件的完整路径，路径名必须是utf-8
  * @param[in] res_cb 上传的回调函数， nim_http_up_cb_func回调函数定义见nim_http_def.h
  * @param[in] res_user_data APP的自定义用户数据，SDK只负责传回给回调函数res_cb，不做任何处理！
  * @param[in] prg_cb 上传进度的回调函数， nim_http_up_prg_cb_func回调函数定义见nim_http_def.h
  * @param[in] prg_user_data APP的自定义用户数据，SDK只负责传回给回调函数prg_cb，不做任何处理！
  * @return void 无返回值
  */
NIM_SDK_DLL_API void nim_http_up(const char *local_file, nim_http_up_cb_func res_cb, const void *res_user_data, nim_http_up_prg_cb_func prg_cb, const void *prg_user_data);

/** @fn void nim_http_dl(const char *nos_url, nim_http_dl_cb_func res_cb, const void *res_user_data, nim_http_dl_prg_cb_func prg_cb, const void *prg_user_data)
  * 下载资源
  * @param[in] nos_url 下载资源的URL
  * @param[in] res_cb 下载的回调函数， nim_http_up_cb_func回调函数定义见nim_http_def.h
  * @param[in] res_user_data APP的自定义用户数据，SDK只负责传回给回调函数res_cb，不做任何处理！
  * @param[in] prg_cb 下载进度的回调函数， nim_http_up_prg_cb_func回调函数定义见nim_http_def.h
  * @param[in] prg_user_data APP的自定义用户数据，SDK只负责传回给回调函数prg_cb，不做任何处理！
  * @return void 无返回值
  */
NIM_SDK_DLL_API void nim_http_dl(const char *nos_url, nim_http_dl_cb_func res_cb, const void *res_user_data, nim_http_dl_prg_cb_func prg_cb, const void *prg_user_data);
#ifdef __cplusplus
};
#endif //__cplusplus
#endif //NIM_SDK_DLL_API_NIM_HTTP_H_