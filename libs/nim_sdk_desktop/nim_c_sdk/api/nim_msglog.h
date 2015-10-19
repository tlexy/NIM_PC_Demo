﻿/** @file nim_msglog.h
  * @brief NIM SDK提供的消息历史接口 
  * @copyright (c) 2015, NetEase Inc. All rights reserved
  * @author Oleg
  * @date 2015/2/1
  */
#ifndef NIM_SDK_DLL_API_NIM_MSGLOG_H_
#define NIM_SDK_DLL_API_NIM_MSGLOG_H_

#include "nim_sdk_dll.h"
#include "nim_msglog_def.h"

#ifdef __cplusplus
extern"C"
{
#endif
/** @fn void nim_msglog_query_msg_async(const char *account_id, NIMSessionType to_type, int limit_count, __int64 last_time, const char *json_extension, nim_msglog_query_cb_func cb, const void *user_data)
  * 查询本地消息（按时间逆序起查，逆序排列）
  * @param[in] account_id	会话id，对方的account id或者群组tid
  * @param[in] to_type	    会话类型
  * @param[in] limit_count	一次查询数量，建议20
  * @param[in] last_time	上次查询最后一条消息的时间戳（按时间逆序起查，即最小的时间戳）
  * @param[in] json_extension json扩展参数（备用，目前不需要）
  * @param[in] cb			查询本地消息的回调函数， nim_msglog_query_cb_func回调函数定义见nim_msglog_def.h
  * @param[in] user_data	APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
  * @return void 无返回值
  */
NIM_SDK_DLL_API void nim_msglog_query_msg_async(const char *account_id, NIMSessionType to_type, int limit_count, __int64 last_time, const char *json_extension, nim_msglog_query_cb_func cb, const void *user_data);

/** @fn void nim_msglog_query_msg_online_async(const char *id, NIMSessionType to_type, int limit_count, __int64 from_time, __int64 end_time, __int64 end_msg_id, bool reverse, bool need_save_to_local, const char *json_extension, nim_msglog_query_cb_func cb, const void *user_data)
  * 在线查询消息（不包括系统消息）
  * @param[in] id				会话id，对方的account id或者群组tid
  * @param[in] to_type			会话类型
  * @param[in] limit_count		本次查询的消息条数上限(最多100条)
  * @param[in] from_time		起始时间点，单位：毫秒
  * @param[in] end_time			结束时间点，单位：毫秒
  * @param[in] end_msg_id		结束查询的最后一条消息的server_msg_id(不包含在查询结果中) 
  * @param[in] reverse			true：反向查询(按时间正序起查，正序排列)，false：按时间逆序起查，逆序排列（建议默认为false）
  * @param[in] need_save_to_local true: 将在线查询结果保存到本地，false: 不保存
  * @param[in] json_extension	json扩展参数（备用，目前不需要）
  * @param[in] cb				在线查询消息的回调函数， nim_msglog_query_cb_func回调函数定义见nim_msglog_def.h
  * @param[in] user_data		APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
  * @return void 无返回值
  */
NIM_SDK_DLL_API void nim_msglog_query_msg_online_async(const char *id, 
													   NIMSessionType to_type, 
													   int limit_count, 
													   __int64 from_time, 
													   __int64 end_time,
													   __int64 end_msg_id,
													   bool reverse,
													   bool need_save_to_local,
													   const char *json_extension, 
													   nim_msglog_query_cb_func cb, 
													   const void *user_data);

/** @fn void nim_msglog_query_msg_by_options_async(NIMMsgLogQueryRange query_range, const char *ids, int limit_count, __int64 from_time, __int64 end_time, __int64 end_msg_id, bool reverse, NIMMessageType msg_type, const char *search_content, const char *json_extension, nim_msglog_query_cb_func cb, const void *user_data)
  * 根据指定条件查询本地消息（不包括系统消息）
  * @param[in] query_range		消息历史的检索范围（目前暂不支持某些范围的组合检索，详见NIMMsgLogQueryRange说明）
  * @param[in] ids				会话id（对方的account id或者群组tid）的集合，如果有多个，则用逗号分隔（目前暂不支持多个的组合检索，详见NIMMsgLogQueryRange说明）
  * @param[in] limit_count		本次查询的消息条数上限(默认100条)
  * @param[in] from_time		起始时间点，单位：毫秒
  * @param[in] end_time			结束时间点，单位：毫秒
  * @param[in] end_msg_id		结束查询的最后一条消息的client_msg_id(不包含在查询结果中)（暂不启用） 
  * @param[in] reverse			true：反向查询(按时间正序起查，正序排列)，false：按时间逆序起查，逆序排列（建议默认为false）
  * @param[in] msg_type			检索的消息类型（目前只支持kNIMMessageTypeText、kNIMMessageTypeImage和kNIMMessageTypeFile这几种类型消息）
  * @param[in] search_content	检索文本（目前只支持kNIMMessageTypeText和kNIMMessageTypeFile这两种类型消息的文本关键字检索，即支持文字消息和文件名的检索。如果合并检索，需使用未知类型消息kNIMMessageTypeUnknown）
  * @param[in] json_extension	json扩展参数（备用，目前不需要）
  * @param[in] cb				本地查询消息的回调函数， nim_msglog_query_cb_func回调函数定义见nim_msglog_def.h
  * @param[in] user_data		APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
  * @return void 无返回值
  */
NIM_SDK_DLL_API void nim_msglog_query_msg_by_options_async(NIMMsgLogQueryRange query_range, 
														   const char *ids, 
														   int limit_count, 
														   __int64 from_time, 
														   __int64 end_time,
														   __int64 end_msg_id,
														   bool reverse,
														   NIMMessageType msg_type,
														   const char *search_content,
														   const char *json_extension, 
														   nim_msglog_query_cb_func cb, 
														   const void *user_data);

/** @fn void nim_msglog_batch_status_read_async(const char *account_id, NIMSessionType to_type, const char *json_extension, nim_msglog_res_ex_cb_func cb, const void *user_data)
  * 批量设置未读状态为已读消息状态
  * @param[in] account_id	会话id，对方的account id或者群组tid
  * @param[in] to_type	    会话类型
  * @param[in] json_extension json扩展参数（备用，目前不需要）
  * @param[in] cb			操作结果的回调函数， nim_msglog_res_ex_cb_func回调函数定义见nim_msglog_def.h
  * @param[in] user_data	APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
  * @return void 无返回值
  */
NIM_SDK_DLL_API void nim_msglog_batch_status_read_async(const char *account_id, NIMSessionType to_type, const char *json_extension, nim_msglog_res_ex_cb_func cb, const void *user_data);

/** @fn void nim_msglog_set_status_async(const char *msg_id, NIMMsgLogStatus msglog_status, const char *json_extension, nim_msglog_res_cb_func cb, const void *user_data)
  * 设置消息状态
  * @param[in] msg_id		消息id
  * @param[in] msglog_status 消息状态枚举值
  * @param[in] json_extension json扩展参数（备用，目前不需要）
  * @param[in] cb			操作结果的回调函数， nim_msglog_res_cb_func回调函数定义见nim_msglog_def.h
  * @param[in] user_data	APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
  * @return void 无返回值
  */
NIM_SDK_DLL_API void nim_msglog_set_status_async(const char *msg_id, NIMMsgLogStatus msglog_status, const char *json_extension, nim_msglog_res_cb_func cb, const void *user_data);

/** @fn void nim_msglog_set_sub_status_async(const char *msg_id, NIMMsgLogSubStatus msglog_sub_status, const char *json_extension, nim_msglog_res_cb_func cb, const void *user_data)
  * 设置消息子状态
  * @param[in] msg_id		消息id
  * @param[in] msglog_sub_status 消息子状态枚举值
  * @param[in] json_extension json扩展参数（备用，目前不需要）
  * @param[in] cb			操作结果的回调函数， nim_msglog_res_cb_func回调函数定义见nim_msglog_def.h
  * @param[in] user_data	APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
  * @return void 无返回值
  */
NIM_SDK_DLL_API void nim_msglog_set_sub_status_async(const char *msg_id, NIMMsgLogSubStatus msglog_sub_status, const char *json_extension, nim_msglog_res_cb_func cb, const void *user_data);

/** @fn void nim_msglog_write_db_only_async(const char *account_id, NIMSessionType to_type, const char *msg_id, const char *json_msg, const char *json_extension, nim_msglog_res_cb_func cb, const void *user_data)
  * 只往本地消息历史数据库里写入一条消息（如果已存在这条消息，则更新。通常是APP的本地自定义消息，并不会发给服务器）
  * @param[in] account_id	会话id，对方的account id或者群组tid
  * @param[in] to_type	    会话类型
  * @param[in] msg_id		消息id
  * @param[in] json_msg		消息体Json string (Keys SEE MORE `nim_talk_def.h` 『消息结构 Json Keys』)
  * @param[in] json_extension json扩展参数（备用，目前不需要）
  * @param[in] cb			操作结果的回调函数， nim_msglog_res_cb_func回调函数定义见nim_msglog_def.h
  * @param[in] user_data	APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
  * @return void 无返回值
  */
NIM_SDK_DLL_API void nim_msglog_write_db_only_async(const char *account_id, NIMSessionType to_type, const char *msg_id, const char *json_msg, const char *json_extension, nim_msglog_res_cb_func cb, const void *user_data);

/** @fn void nim_msglog_batch_status_delete_async(const char *account_id, NIMSessionType to_type, const char *json_extension, nim_msglog_res_ex_cb_func cb, const void *user_data)
  * 批量删除指定对话的消息。删除成功后，将相应会话项的最后一条消息的状态kNIMSessionMsgStatus设置为已删除状态，并通过nim_session_reg_change_cb注册的回调通知上层相应会话项的kNIMSessionCommandMsgDeleted事件。
  * @param[in] account_id	会话id，对方的account id或者群组tid
  * @param[in] to_type	    会话类型
  * @param[in] json_extension json扩展参数（备用，目前不需要）
  * @param[in] cb			操作结果的回调函数， nim_msglog_res_ex_cb_func回调函数定义见nim_msglog_def.h
  * @param[in] user_data	APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
  * @return void 无返回值
  */
NIM_SDK_DLL_API void nim_msglog_batch_status_delete_async(const char *account_id, NIMSessionType to_type, const char *json_extension, nim_msglog_res_ex_cb_func cb, const void *user_data);

/** @fn void nim_msglog_delete_by_session_type_async(bool delete_sessions, NIMSessionType to_type, const char *json_extension, nim_msglog_res_ex_cb_func cb, const void *user_data)
  * 删除指定会话类型的所有消息
  * @param[in] delete_sessions 是否删除指定会话类型的所有会话列表项。
  *							   ture则删除，并通过nim_session_reg_change_cb注册的回调通知上层kNIMSessionCommandRemoveAllP2P或kNIMSessionCommandRemoveAllTeam事件（不会触发每个会话项的kNIMSessionCommandRemove事件）；
  *							   false则不删除，并将指定会话类型的所有会话项的最后一条消息的状态kNIMSessionMsgStatus设置为已删除状态，并通过nim_session_reg_change_cb注册的回调通知上层kNIMSessionCommandAllP2PMsgDeleted或kNIMSessionCommandAllTeamMsgDeleted事件（不会触发每个会话项的kNIMSessionCommandUpdate事件，避免频繁通知上层）。
  * @param[in] to_type	    会话类型
  * @param[in] json_extension json扩展参数（备用，目前不需要）
  * @param[in] cb			操作结果的回调函数， nim_msglog_res_ex_cb_func回调函数定义见nim_msglog_def.h
  * @param[in] user_data	APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
  * @return void 无返回值
  */
NIM_SDK_DLL_API void nim_msglog_delete_by_session_type_async(bool delete_sessions, NIMSessionType to_type, const char *json_extension, nim_msglog_res_ex_cb_func cb, const void *user_data);

/** @fn void nim_msglog_delete_async(const char *account_id, NIMSessionType to_type, const char *msg_id, const char *json_extension, nim_msglog_res_cb_func cb, const void *user_data)
  * 删除指定一条消息
  * @param[in] account_id	会话id，对方的account id或者群组tid
  * @param[in] to_type	    会话类型
  * @param[in] msg_id		消息id
  * @param[in] json_extension json扩展参数（备用，目前不需要）
  * @param[in] cb			操作结果的回调函数， nim_msglog_res_cb_func回调函数定义见nim_msglog_def.h
  * @param[in] user_data	APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
  * @return void 无返回值
  */
NIM_SDK_DLL_API void nim_msglog_delete_async(const char *account_id, NIMSessionType to_type, const char *msg_id, const char *json_extension, nim_msglog_res_cb_func cb, const void *user_data);

/** @fn void nim_msglog_delete_all_async(bool delete_sessions, const char *json_extension, nim_msglog_res_cb_func cb, const void *user_data)
  * 删除全部消息历史
  * @param[in] delete_sessions 是否删除所有会话列表项（即全部最近联系人）。
  *							   ture则删除，并通过nim_session_reg_change_cb注册的回调通知上层kNIMSessionCommandRemoveAll事件（不会触发每个会话项的kNIMSessionCommandRemove事件）；
  *							   false则不删除，并将所有会话项的最后一条消息的状态kNIMSessionMsgStatus设置为已删除状态，并通过nim_session_reg_change_cb注册的回调通知上层kNIMSessionCommandAllMsgDeleted事件（不会触发每个会话项的kNIMSessionCommandUpdate事件，避免频繁通知上层）。
  * @param[in] json_extension json扩展参数（备用，目前不需要）
  * @param[in] cb			操作结果的回调函数， nim_msglog_res_cb_func回调函数定义见nim_msglog_def.h
  * @param[in] user_data	APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
  * @return void 无返回值
  */
NIM_SDK_DLL_API void nim_msglog_delete_all_async(bool delete_sessions, const char *json_extension, nim_msglog_res_cb_func cb, const void *user_data);

/** @fn void nim_msglog_export_db_async(const char *dst_path, const char *json_extension, nim_msglog_res_cb_func cb, const void *user_data)
  * 导出整个消息历史DB文件（不包括系统消息历史）。直接拷贝DB文件即可，SDK层不返回进度给APP层。
  * @param[in] dst_path		导出时保存的目标全路径（UTF-8编码）。
  * @param[in] json_extension json扩展参数（备用，目前不需要）
  * @param[in] cb			操作结果的回调函数， nim_msglog_res_cb_func回调函数定义见nim_msglog_def.h
  * @param[in] user_data	APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
  * @return void 无返回值
  */
NIM_SDK_DLL_API void nim_msglog_export_db_async(const char *dst_path, const char *json_extension, nim_msglog_res_cb_func cb, const void *user_data);

/** @fn void nim_msglog_import_db_async(const char *src_path, const char *json_extension, nim_msglog_res_cb_func res_cb, const void *res_user_data, nim_msglog_import_prg_cb_func prg_cb, const void *prg_user_data)
  * 导入消息历史DB文件（不包括系统消息历史）。先验证是否自己的消息历史文件和DB加密密钥(见nim_client_def.h里的kNIMDataBaseEncryptKey），如果验证不通过，则不导入。
  * @param[in] src_path			导入源文件的全路径（UTF-8编码）。
  * @param[in] json_extension	json扩展参数（备用，目前不需要）
  * @param[in] res_cb			操作结果的回调函数， nim_msglog_res_cb_func回调函数定义见nim_msglog_def.h
  * @param[in] res_user_data	APP的自定义用户数据，SDK只负责传回给回调函数res_cb，不做任何处理！
  * @param[in] prg_cb			导入进度的回调函数， nim_msglog_import_prg_cb_func回调函数定义见nim_msglog_def.h
  * @param[in] prg_user_data	APP的自定义用户数据，SDK只负责传回给回调函数prg_cb，不做任何处理！
  * @return void 无返回值
  */
NIM_SDK_DLL_API void nim_msglog_import_db_async(const char *src_path, const char *json_extension, nim_msglog_res_cb_func res_cb, const void *res_user_data, nim_msglog_import_prg_cb_func prg_cb, const void *prg_user_data);

#ifdef __cplusplus
};
#endif //__cplusplus
#endif //NIM_SDK_DLL_API_NIM_MSGLOG_H_