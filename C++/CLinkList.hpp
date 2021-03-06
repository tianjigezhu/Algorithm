/*****************************************************************************
*  C++ Algorithm tool library                                                *
*  Copyright (C) 2017 Tianjigezhu tianjigezhuhn@aliyun.com                   *
*                                                                            *
*  This file is part of C++ Algorithm.                                       *
*                                                                            *
*  This program is free software; you can redistribute it and/or modify it   *
*  under the terms of the GNU General Public License version 3 as published  *
*  by the Free Software Foundation.                                          *
*                                                                            *
*  You should hava received a copy of the GNU General Public License along   *
*  with C++ Algorithm. If not, see <http://www.gnu.org/licenses/>.           *
*                                                                            *
*  Unless required by applicable law or agreed to in writing, software       *
*  distributed under the License is distributed on an "AS IS" BASIS,         *
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  *
*  See the License for the specific language governing permissions and       *
*  limitations under the License.                                            *
*                                                                            *
*  @file     CLinkLIst.hpp                                                   *
*  @brief    Double link list head file                                      *
*  Define double link list template class.                                   *
*                                                                            *
*  @author   Tianjigezhu                                                     *
*  @email    tianjigezhuhn@aliyun.com                                        *
*  @version  1.0.0.1                                                         *
*  @date     2017/08/05                                                      *
*  @license  GNU General Public License (GPL)                                *
*                                                                            *
*----------------------------------------------------------------------------*
*  Remark         : Description                                              *
*----------------------------------------------------------------------------*
*  Change History :                                                          *
*  <Date>     | <Version> | <Author>       | <Description>                   *
*----------------------------------------------------------------------------*
*  2017/08/05 | 1.0.0.1   | Tianjigezhu    | Create file                     *
*----------------------------------------------------------------------------*
*                                                                            *
*****************************************************************************/


#ifndef __PARADISE_ALGORITHM_C_LINK_LIST_HPP__
#define __PARADISE_ALGORITHM_C_LINK_LIST_HPP__

#include "ILinkList.hpp"
#include "Type.hpp" 

/**
 * @brief 定义了命名空间Paradise，包含其他命名空间
 * 命名空间Paradise是所有项目的最高命名空间，其他项目的命名空间都必须定义在这命名空间了内。
 */
namespace Paradise
{

/**
 * @brief 定义了命名空间Algorithm
 * 命名空间Algorithm是C++算法的命名空间，所有C++数据结构与算法都定义在此命名空间内。
 */
namespace Algorithm
{

/**
 *@brief 单链表类的内部数据节点模板。
 */
template<class T>
struct SLinkListNode
{
	T m_value;
	SLinkListNode<T> *m_pnext;
	SLinkListNode<T> *m_pprevious;

	SLinkListNode() { m_pnext = NULL; m_pprevious = NULL; }
};

/**
 * @class CLinkList
 *
 * @brief 双向链表模板类
 * 本类是双向链表表类模板的定义，继承链表接口。
 * 
 */	
template<class T>
class CLinkList : public ILinkList<T>
{
// 定义构造函数、复制构造函数、析构函数
public:
	/**
	 * @brief 构造函数
	 */
	CLinkList();

	/**
	 * @brief 析构函数
	 */
	virtual ~CLinkList();

	/**
	 * @brief 复制构造函数
	 */
	CLinkList(const CLinkList<T>& otherList);

// 重定义操作符
public:
	/**
	 * @brief 重载赋值操作符
	 */
	const CLinkList<T>& operator==(const CLinkList<T>& otherList);

// 其余成员函数声明
public:
	/**
	 * @brief 判断链表是否为空
	 *
	 * @return 链表是空链表返回false，否则返回true
	 */
	Paradise::Type::EBool isEmpty() const;

	/**
	 * @brief 计算链表长度
	 *
	 * @return 返回链表的长度
	 */
	int length() const;

	/**
	 * @brief 获取链表第一个元素值
	 * 在使用之前应先判断链表是否有值。
	 *
	 * @return 链表第一个元素值
	 */
	T front() const;

	/**
	 * @brief 获取链表最后一个元素值
	 * 在使用之前应先判断链表是否有值。
	 *
	 * @return 链表最后一个元素值
	 */
	T back() const;

	/**
	 * @brief 查询指定值是否存在链表中。
	 *
	 * @return 返回指定值是否在链表中，如果存在则返回true，否则返回false
	 */
	Paradise::Type::EBool search(const T& searchItem) const;

	/**
	 * @brief 获取指定索引的节点值。
	 * 如果索引超出范围，则会打印错误，并退出。索引从0开始。
	 *
	 * @return 返回指定索引的节点值。
	 */
	T valueAt(int index) const;

	/**
	 * @brief 将指定值插在链表的开头
	 */
	void insertFirst(const T& newItem);

	/**
	 * @brief 将指定值插在链表的结尾
	 */
	void insertLast(const T& newItem);

	/**
	 * @brief 删除指定值
	 */
	void deleteItem(const T& deleteItem);

// 定义成员变量
protected:
	/**
	 * @brief 链表的长度
	 */
	int m_count;

	/**
	 * @brief 链表头指针
	 */
	SLinkListNode<T>* m_pfirstNode;

	/**
	 * @brief 链表尾部指针
	 */
	SLinkListNode<T>* m_plastNode;

// 私有成员函数定义
private:
	/**
	 * @brief 删除链表
	 */
	void destroyList();

	/**
	 * @brief 复制链表
	 */
	void copyList(const SLinkListNode<T>& otherList);

}; // CLinkList

} // Algorithm

} // Paradise

#include "CLinkList_impl.hpp"

#endif // __PARADISE_ALGORITHM_C_LINK_LIST_HPP__