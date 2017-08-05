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

#include "CSingleLinkList.hpp"

/**
 * @brief 构造函数
 */
CSingleLinkList::CSingleLinkList()
  : m_count(0), m_pfirstNode(NULL), m_plastNode(NULL)
{
}

/**
 * @brief 析构函数
 */
CSingleLinkList::~CSingleLinkList()
{
	// 调用函数删除链表
	destroyList();
}

/**
 * @brief 复制构造函数
 */
CSingleLinkList::CSingleLinkeList(const CSingleLinkList<T>& otherList)
{
	// 调用函数复制链表
	copyList(otherList)
}

/**
 * @brief 删除链表
 */
CSingleLinkList::destroyList()
{
	// 循环删除每一个成员
	SSingleLinkListNode* pdeleteItem = NULL;
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
void CSingleLinkList::copyList(const CSingleLinkList<T>& otherList)
{
	// 判断复制的链表是否是空链表
	// 如果为空，则删除本链表
	if (otherList.isEmpty()) {
		destroyList();
		return ;
	}

	// 定义指向本链表和复制链表第一个节点的指针
	SSingleLinkListNode *pfirstListNode = NULL, *psecondListNode = NULL;
	pfirstListNode = m_pfirstNode;
	psecondListNode = otherList->m_pfirstNode;
	m_count = otherList.length();

	// 判断本链表第一个节点是否存在
	// 如果不存在则构造第一个节点并赋值
	if (!pfirstListNode) {
		pfirstListNode = new SSingleLinkListNode;
		pfirstListNode->value = psecondListNode->value;
		pfirstListNode->m_pnext = NULL;

		m_pfirstNode = pfirstListNode;
		m_plastNode = m_pfirstNode;
	}

	// 复制每一个节点，从第二个节点开始
	psecondListNode = psecondListNode->m_pnext;
	pfirstListNode = pfirstListNode->m_pnext;
	while (psecondListNode) {
		if (pfirstListNode) {
			pfirstListNode->value = psecondListNode->value;
		} else {
			pfirstListNode = new SSingleLinkListNode;
			pfirstListNode->value = psecondListNode->value;
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
		SSingleLinkListNode* pdeleteItem = NULL;
		pdeleteItem = pfirstListNode;
		pfirstListNode = pfirstListNode->m_pnext;
		delete pdeleteItem;
	}

	m_plastNode->m_pnext = NULL;
	pfirstListNode = NULL;
	psecondListNode = NULL;
}