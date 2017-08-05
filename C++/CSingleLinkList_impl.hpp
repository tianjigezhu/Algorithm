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
*  @file     CSingleLinkList.cpp                                             *
*  @brief    SingleLinkList source file                                      *
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

#ifndef __PARADISE_ALGORITHM_CSINGLE_LINK_LIST_IMPL_HPP__
#define __PARADISE_ALGORITHM_CSINGLE_LINK_LIST_IMPL_HPP__
//#include "CSingleLinkList.hpp"


#include <stdlib.h>

/**
 * @brief 构造函数
 */
template<class T>
Paradise::Algorithm::CSingleLinkList<T>::CSingleLinkList()
  : m_count(0), m_pfirstNode(NULL), m_plastNode(NULL)
{
}

/**
 * @brief 析构函数
 */
template<class T>
Paradise::Algorithm::CSingleLinkList<T>::~CSingleLinkList()
{
	// 调用函数删除链表
	destroyList();
}

/**
 * @brief 复制构造函数
 */
template<class T>
Paradise::Algorithm::CSingleLinkList<T>::CSingleLinkList(const Paradise::Algorithm::CSingleLinkList<T>& otherList)
{
	// 调用函数复制链表
	copyList(otherList);
}

/**
 * @brief 重载赋值操作符
 */
template<class T>
const Paradise::Algorithm::CSingleLinkList<T>& 
Paradise::Algorithm::CSingleLinkList<T>::operator==(const Paradise::Algorithm::CSingleLinkList<T>& otherList)
{
	copyList(otherList);

	return *this;
}

/**
 * @brief 删除链表
 */
template<class T>
void Paradise::Algorithm::CSingleLinkList<T>::destroyList()
{
	// 循环删除每一个成员
	SSingleLinkListNode<T>* pdeleteItem = NULL;
	while (m_pfirstNode) {
		pdeleteItem = m_pfirstNode;
		m_pfirstNode = m_pfirstNode->m_pnext;
		delete pdeleteItem;
	}

	// 将头尾指针设置为NULL，防止使用链表导致异常
	m_pfirstNode = NULL;
	m_plastNode = NULL;
	m_count = 0;
}

/**
 * @brief 复制链表
 */
template<class T>
void Paradise::Algorithm::CSingleLinkList<T>::copyList(const Paradise::Algorithm::CSingleLinkList<T>& otherList)
{
	// 判断复制的链表是否是空链表
	// 如果为空，则删除本链表
	if (otherList.isEmpty()) {
		destroyList();
		return ;
	}

	// 定义指向本链表和复制链表第一个节点的指针
	SSingleLinkListNode<T> *pfirstListNode = NULL, *psecondListNode = NULL;
	pfirstListNode = m_pfirstNode;
	psecondListNode = otherList->m_pfirstNode;
	m_count = otherList.length();

	// 判断本链表第一个节点是否存在
	// 如果不存在则构造第一个节点并赋值
	if (!pfirstListNode) {
		pfirstListNode = new SSingleLinkListNode<T>;
		pfirstListNode->m_value = psecondListNode->m_value;
		pfirstListNode->m_pnext = NULL;

		m_pfirstNode = pfirstListNode;
		m_plastNode = m_pfirstNode;
	}

	// 复制每一个节点，从第二个节点开始
	psecondListNode = psecondListNode->m_pnext;
	pfirstListNode = pfirstListNode->m_pnext;
	while (psecondListNode) {
		if (pfirstListNode) {
			pfirstListNode->m_value = psecondListNode->m_value;
		} else {
			pfirstListNode = new SSingleLinkListNode<T>;
			pfirstListNode->m_value = psecondListNode->m_value;
			pfirstListNode->m_pnext = NULL;
			m_plastNode->m_pnext = pfirstListNode;		
		}

		/*
		 * 将pfirstListNode赋值给m_plastNode，当
		 * 循环复制结束之后m_plastNode恰好指向本链表最后一个节点
		 */
		m_plastNode = pfirstListNode;
		psecondListNode = psecondListNode->m_pnext;
		pfirstListNode = pfirstListNode->m_pnext;
	}

	// 复制之后删除本链表多余的节点
	if (pfirstListNode) {
		SSingleLinkListNode<T>* pdeleteItem = NULL;
		pdeleteItem = pfirstListNode;
		pfirstListNode = pfirstListNode->m_pnext;
		delete pdeleteItem;
	}

	m_plastNode->m_pnext = NULL;
	pfirstListNode = NULL;
	psecondListNode = NULL;
}

/**
 * @brief 判断链表是否为空
 *
 * @return 链表是空链表返回false，否则返回true
 */
template<class T>
Paradise::Type::EBool Paradise::Algorithm::CSingleLinkList<T>::isEmpty() const
{
	if (NULL == m_pfirstNode)
		return Paradise::Type::FALSE;
	return Paradise::Type::TRUE;
}

/**
 * @brief 计算链表长度
 *
 * @return 返回链表的长度
 */
template<class T>
int Paradise::Algorithm::CSingleLinkList<T>::length() const
{
	return m_count;
}

/**
 * @brief 获取链表第一个元素值
 * 在使用之前应先判断链表是否有值。
 *
 * @return 链表第一个元素值
 */
template<class T>
T Paradise::Algorithm::CSingleLinkList<T>::front() const
{
	return m_pfirstNode->m_value;
}

/**
 * @brief 获取链表最后一个元素值
 * 在使用之前应先判断链表是否有值。
 *
 * @return 链表最后一个元素值
 */
template<class T>
T Paradise::Algorithm::CSingleLinkList<T>::back() const
{
	return m_plastNode->m_value;
}

/**
 * @brief 查询指定值是否存在链表中。
 *
 * @return 返回指定值是否在链表中，如果存在则返回true，否则返回false
 */
template<class T>
Paradise::Type::EBool Paradise::Algorithm::CSingleLinkList<T>::search(const T& searchItem) const
{
	SSingleLinkListNode<T>* psearchNode = m_pfirstNode;
	while (psearchNode) {
		if (searchItem == psearchNode->m_value)
			return Paradise::Type::TRUE;
		psearchNode = psearchNode->m_pnext;
	}

	return Paradise::Type::FALSE;
}

/**
 * @brief 将指定值插在链表的开头
 */
template<class T>
void Paradise::Algorithm::CSingleLinkList<T>::insertFirst(const T& newItem)
{
	SSingleLinkListNode<T>* pnewNode = new SSingleLinkListNode<T>;
	pnewNode->m_value = newItem;
	pnewNode->m_pnext = m_pfirstNode;
	m_pfirstNode = pnewNode;
	++m_count;
}

/**
 * @brief 将指定值插在链表的结尾
 */
template<class T>
void Paradise::Algorithm::CSingleLinkList<T>::insertLast(const T& newItem)
{
	SSingleLinkListNode<T>* pnewNode = new SSingleLinkListNode<T>;
	pnewNode->m_value = newItem;
	pnewNode->m_pnext = NULL;
	m_plastNode->m_pnext = pnewNode;
	m_plastNode = pnewNode;
	++m_count;
}

/**
 * @brief 删除指定值
 */
template<class T>
void Paradise::Algorithm::CSingleLinkList<T>::deleteItem(const T& deleteItem)
{

}

#endif // #ifndef __PARADISE_ALGORITHM_CSINGLE_LINK_LIST_IMPL_HPP__