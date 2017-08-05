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
*  @file     ISingleLinkList.hpp                                             *
*  @brief    SingleLinkList head file                                        *
*  Define SingleLinkeList template class.                                    *
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

#ifndef __PARADISE_ALGORITHM_I_SINGLE_LINK_LIST_HPP__
#define __PARADISE_ALGORITHM_I_SINGLE_LINK_LIST_HPP__

#include "Paradise.hpp"

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
 * @class ISingleLinkList
 *
 * @brief 单链表接口模板
 * 本类是单链表接口的定义，接口类为虚基类。
 * 
 */	
template<class T>
class ISingleLinkList
{
// 定义构造函数、复制构造函数、析构函数
public:
	/**
	 * @brief 构造函数
	 */
	ISingleLinkList() = 0;

	/**
	 * @brief 析构函数
	 */
	virtual ~ISingleLinkList() = 0

	/**
	 * @brief 复制构造函数
	 */
	ISingleLinkeList(const ISingleLinkList<T>& other) = 0;

// 重定义操作符
public:
	/**
	 * @brief 重载赋值操作符
	 */
	const ISingleLinkList<T>& operator==(const ISingleLinkList<T>& other) = 0;

public:
	/**
	 * @brief 判断链表是否为空
	 *
	 * @return 链表是空链表返回false，否则返回true
	 */
	virtual bool isEmpty() const = 0;

	/**
	 * @brief 计算链表长度
	 *
	 * @return 返回链表的长度
	 */
	virtual int length() const = 0;

	/**
	 * @brief 获取链表第一个元素值
	 * 在使用之前应先判断链表是否有值。
	 *
	 * @return 链表第一个元素值
	 */
	virtual T font() const = 0;

	/**
	 * @brief 获取链表最后一个元素值
	 * 在使用之前应先判断链表是否有值。
	 *
	 * @return 链表最后一个元素值
	 */
	virtual T back() const = 0;

	/**
	 * @brief 查询指定值是否存在链表中。
	 *
	 * @return 返回指定值是否在链表中，如果存在则返回true，否则返回false
	 */
	virtual bool search(const T& searchItem) const = 0;

	/**
	 * @brief 将指定值插在链表的开头
	 */
	virtual void insertFirst(const T& newItem) = 0;

	/**
	 * @brief 将指定值插在链表的结尾
	 */
	virtual void insertLast(const T& newItem) = 0;

	/**
	 * @brief 删除指定值
	 */
	virtual void deleteItem(const T& deleteItem) = 0;

// 私有成员函数定义
private:
	/**
	 * @brief 删除链表
	 */
	virtual void destroyList() = 0;

	/**
	 * @brief 复制链表
	 */
	virtual void copyList(const CSingleLinkList<T>& otherList) = 0;

}; // ISingleLinkList

} // Algorithm

} // Paradise 

#endif // __PARADISE_ALGORITHM_I_SINGLE_LINK_LIST_HPP__