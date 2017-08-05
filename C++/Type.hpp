/*****************************************************************************
*  C++ custom type tool library                                              *
*  Copyright (C) 2017 Tianjigezhu tianjigezhuhn@aliyun.com                   *
*                                                                            *
*  This file is part of C++ Type.                                            *
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
*  @file     Type.hpp                                                        *
*  @brief    Custom types head file                                          *
*  Define Custom types.                                                      *
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

#ifndef __PARADISE_TYPE_HPP__
#define __PARADISE_TYPE_HPP__

/**
 * @brief 定义了命名空间Paradise，包含其他命名空间
 * 命名空间Paradise是所有项目的最高命名空间，其他项目的命名空间都必须定义在这命名空间了内。
 */
namespace Paradise
{

/**
 * @brief 定义了命名空间Type
 * 命名空间Type是C++所有除算法外自定义类型的命名空间
 */
namespace Type
{

enum EBool
{
	FALSE,
	TRUE
};

//const void* NULL = (void*)0;

} // namespace Type

}

#endif // __PARADISE_TYPE_HPP__