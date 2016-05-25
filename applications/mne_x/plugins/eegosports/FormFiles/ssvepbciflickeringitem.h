//=============================================================================================================
/**
* @file     ssvepBCIFlickeringItem.h
* @author   Viktor Klüber <viktor.klueber@tu-ilmenau.de>;
*           Lorenz Esch <Lorenz.Esch@tu-ilmenau.de>;
*           Christoph Dinh <chdinh@nmr.mgh.harvard.edu>;
*           Matti Hamalainen <msh@nmr.mgh.harvard.edu>
* @version  1.0
* @date     May 2016
*
* @section  LICENSE
*
* Copyright (C) 2014, Lorenz Esch, Christoph Dinh and Matti Hamalainen. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that
* the following conditions are met:
*     * Redistributions of source code must retain the above copyright notice, this list of conditions and the
*       following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
*       the following disclaimer in the documentation and/or other materials provided with the distribution.
*     * Neither the name of MNE-CPP authors nor the names of its contributors may be used
*       to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*
* @brief    Contains the declaration of the ssvepBCIFlickeringItem class.
*
*/

#ifndef SSVEPBCIFLICKERINGITEM_H
#define SSVEPBCIFLICKERINGITEM_H

//*************************************************************************************************************
//=============================================================================================================
// QT INCLUDES
//=============================================================================================================

#include <QList>
#include <QListIterator>
#include <QOpenGLPaintDevice>
#include <QtCore>
#include <QPainter>

//*************************************************************************************************************
//=============================================================================================================
// DEFINE NAMESPACE ssvepBCIScreen
//=============================================================================================================

namespace EEGoSportsPlugin
{


//=============================================================================================================
/**
* DECLARE CLASS ssvepBCIFlickeringItem
*
* @brief ssvepBCIFlickeringItem provices declaration and definition of flickering items which can be attached
* to ssvepbciscreen
*/
class ssvepBCIFlickeringItem
{
public:   
    int                 m_iFreqKey;     /**< getting the adjusted key of the frquency */

    //=========================================================================================================
    /**
    * constructs a ssvepBCIFlickeringItem object
    */
    ssvepBCIFlickeringItem();

    //=========================================================================================================
    /**
    * destroys the ssvepBCIFlickeringItem object
    */
    ~ssvepBCIFlickeringItem();

    //=========================================================================================================
    /**
    * The function sets the relative position of the Item to the screen size
    *
    * @param[in]  x  relative horizontal position. x is element from [0..1]
    * @param[in]  y  relative horizontal position. y is element from [0..1]
    *
    */
    void            setPos(double x, double y);

    //=========================================================================================================
    /**
    * The function sets the relative dimension of the Item to the screen size
    *
    * @param[in]  w  relative width. w is element from [0..1]
    * @param[in]  h  relative height. h is element from [0..1]
    *
    */
    void            setDim(double w, double h);

    //=========================================================================================================
    /**
    * The function sets the order of rendering
    *
    * @param[in]  renderOrder   List of boolean commands where 1 is painting white and 0 is painting black
    * @param[in]  freqKey       key of adjusted frequency
    *
    */
    void setRenderOrder(QList<bool> renderOrder, int freqKey);

    //=========================================================================================================
    /**
    * The function paints the item with the given paint device with all the setted configuration
    *
    * @param[in]  paintDevice  paint device to a Widget
    *
    */
    void paint(QPaintDevice *paintDevice);

    //=========================================================================================================
    /**
    * The function outputs the adjusted frequency key
    *
    * @return saved frequency key
    *
    */
    int getFreq(void);

public slots:
    void chessDim(int rows);

private:
    double m_dPosX;                         /**< realtive vertical position according to screen size; [0..1] */
    double m_dPosY;                         /**< realtive horizontal position according to screen size; [0..1] */
    double m_dWidth;                        /**< realtive width according to screen size; [0..1] */
    double m_dHeight;                       /**< realtive height according to screen size; [0..1] */

    QList<bool>         m_bRenderOrder;     /**< render order of the Item */
    QListIterator<bool> m_bIter;            /**< Iterator of the m_bRenderOrder list */
    bool                m_bFlickerState;    /**< actual Flickerstate [0] paint black [1] paint white */

    bool                m_bChessboard;      /**< enables chessboard feature */
    int                 m_iRows;            /**< number of rows of the chessboard */

};

}       // NAMESPACE
#endif  // SSVEPBCIFLICKERINGITEM_H
