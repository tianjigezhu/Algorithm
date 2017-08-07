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
*  @file     CLinkList.hpp                                                   *
*  @brief    LinkList source file                                            *
*  Define LinkeList template class.                                          *
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

#ifndef __PARADISE_ALGORITHM_C_SINGLE_LINK_LIST_IMPL_HPP__
#define __PARADISE_ALGORITHM_C_SINGLE_LINK_LIST_IMPL_HPP__
//#include "CLinkList.hpp"


#include <stdlib.h>

#include <iostream>

/**
 * @brief 构造函数
 */
template<class T>
Paradise::Algorithm::CLinkList<T>::CLinkList()
  : m_count(0), m_pfirstNode(NULL), m_plastNode(NULL)
{
}

/**
 * @brief 析构函数
 */
template<class T>
Paradise::Algorithm::CLinkList<T>::~CLinkList()
{
	// 调用函数删除链表
	destroyList();
}

/**
 * @brief 复制构造函数
 */
template<class T>
Paradise::Algorithm::CLinkList<T>::CLinkList(const Paradise::Algorithm::CLinkList<T>& otherList)
{
	// 调用函数复制链表
	copyList(otherList);
}

/**
 * @brief 重载赋值操作符
 */
template<class T>
const Paradise::Algorithm::CLinkList<T>& 
Paradise::Algorithm::CLinkList<T>::operator==(const Paradise::Algorithm::CLinkList<T>& otherList)
{
	copyList(otherList);

	return *this;
}

/**
 * @brief 删除链表
 */
template<class T>
void Paradise::Algorithm::CLinkList<T>::destroyList()
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
void Paradise::Algorithm::CLinkList<T>::copyList(const Paradise::Algorithm::CLinkList<T>& otherList)
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

	while (psecondListNode) {
		if (pfirstListNode) {
			pfirstListNode->m_value = psecondListNode->m_value;
		} else {
			pfirstListNode = new SSingleLinkListNode<T>;
			firstListNode->m_value = psecondListNode->m_value;
			pfirstListNode->m_pnext = NULL;
			if (m_plastNode) {
				pfirstListNode->m_pprevious = m_plastNode;
				m_plastNode->m_pnext = pfirstListNode;
			} else {
				m_pfirstNode = m_plastNode = pfirstListNode;
				pfirstListNode->m_pprevious = NULL;
			}
					
		}
	}

	pfirstListNode = NULL;
	psecondListNode = NULL;
}

/**
 * @brief 判断链表是否为空
 *
 * @return 链表是空链表返回false，否则返回true
 */
template<class T>
Paradise::Type::EBool Paradise::Algorithm::CLinkList<T>::isEmpty() const
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
int Paradise::Algorithm::CLinkList<T>::length() const
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
T Paradise::Algorithm::CLinkList<T>::front() const
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
T Paradise::Algorithm::CLinkList<T>::back() const
{
	return m_plastNode->m_value;
}

/**
 * @brief 查询指定值是否存在链表中。
 *
 * @return 返回指定值是否在链表中，如果存在则返回true，否则返回false
 */
template<class T>
Paradise::Type::EBool Paradise::Algorithm::CLinkList<T>::search(const T& searchItem) const
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
 * @brief 获取指定索引的节点值。
 * 如果索引超出范围，则会打印错误，并退出。索引从0开始。
 *
 * @return 返回指定索引的节点值。
 */
template<class T>
T Paradise::Algorithm::CLinkList<T>::valueAt(int index) const
{
	if (index < 0 || index >= m_count) {
		std::cerr << "out of range" << std::endl;
		exit(1);
	}

	SSingleLinkListNode<T>* pcurr = m_pfirstNode;
	for (int i = 0; i < m_count; ++i) {
		if (i == index) {
			return pcurr->m_value;
		}
		pcurr = pcurr->m_pnext;
	}
}

/**
 * @brief 将指定值插在链表的开头
 */
template<class T>
void Paradise::Algorithm::CLinkList<T>::insertFirst(const T& newItem)
{
	SSingleLinkListNode<T>* pnewNode = new SSingleLinkListNode<T>;
	pnewNode->m_value = newItem;
	pnewNode->m_pnext = m_pfirstNode;
	pnewNOde->m_pprevious = NULL;
	m_pfirstNode = pnewNode;
	if (!m_plastNode)
		m_plastNode = m_pfirstNode;
	++m_count;
}

/**
 * @brief 将指定值插在链表的结尾
 */
template<class T>
void Paradise::Algorithm::CLinkList<T>::insertLast(const T& newItem)
{
	SSingleLinkListNode<T>* pnewNode = new SSingleLinkListNode<T>;
	pnewNode->m_value = newItem;
	pnewNode->m_pnext = NULL;

	if (NULL == m_pfirstNode) {
		m_pfirstNode = pnewNode;
		m_plastNode = pnewNode;
		pnewNode->m_pprevious = NULL;
	} else {
		m_plastNode->m_pnext = pnewNode;
		pnewNode->m_pprevious = m_plastNode;
		m_plastNode = pnewNode;
	}
	
	++m_count;
}

/**
 * @brief 删除指定值
 */
template<class T>
void Paradise::Algorithm::CLinkList<T>::deleteItem(const T& deleteItem)
{
	if (!m_pfirstNode)
		return ;

	SSingleLinkListNode<T> *pdeleteNode = NULL, *ptailNode = NULL;
	pdeleteNode = m_pfirstNode;
	while (pdeleteNode) {
		if (pdeleteNode->m_value == deleteItem) {
			// 如果前一个节点存在
			if (pdeleteNode->m_pprevious) {
				// 前一个节点的后向节点指向删除节点的后向节点，至于是否是NULL则不影响
				(pdeleteNode->m_pprevious)->m_pnext = pdeleteNode->m_pnext;
				// 如果删除节点的后向节点存在，则将该后向节点的前向节点指向删除节点的前向节点
				if (pdeleteNode->m_pnext) {
					(pdeleteNode->m_pnext)->m_pprevious = pdeleteNode->m_pprevious;
				}
			} else { // 如果前一个节点不存在
				// 如果后向节点存在，则将后向节点的前向节点设置为NULL。
				if (pdeleteNode->m_pnext) {
					(pdeleteNode->m_pnext)->m_pprevious = NULL;
				} else {
					// 如果后向节点不存在，根据前向节点也不存在，说明本节点是唯一节点
					m_pfirstNode = m_plastNode = NULL;
				}
			}
			delete pdeleteNode;
		} else {
			pdeleteNode = pdeleteNode->m_pnext;
		}
	}
}

#endif // #ifndef __PARADISE_ALGORITHM_C_SINGLE_LINK_LIST_IMPL_HPP__