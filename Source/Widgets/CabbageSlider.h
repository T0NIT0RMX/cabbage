/*
  Copyright (C) 2016 Rory Walsh

  Cabbage is free software; you can redistribute it
  and/or modify it under the terms of the GNU General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  Cabbage is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU General Public
  License along with Csound; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
  02111-1307 USA
*/

#ifndef CABBAGESLIDER_H_INCLUDED
#define CABBAGESLIDER_H_INCLUDED

#include "../CabbageCommonHeaders.h"
#include "CabbageWidgetBase.h"
#include "../LookAndFeel/FlatButtonLookAndFeel.h"

class CabbagePluginEditor;

class CabbageSlider
    : public Component,
      public ValueTree::Listener,
      public CabbageWidgetBase
{
    CabbagePluginEditor* owner;
    ValueTree widgetData;
    Label textLabel;
    float velocity, sliderIncrement, sliderSkew, min, max, value, shouldShowTextBox, trackerInnerRadius, trackerOuterRadius, trackerThickness;
    int decimalPlaces;
    String colour, fontColour, textColour, outlineColour, sliderType, trackerColour, channel, popupText;
    bool shouldDisplayPopup = true;
    Slider slider;
    BubbleMessageComponent popupBubble;

    void mouseDrag (const MouseEvent& event) override;
    void mouseMove (const MouseEvent& event) override;
    void mouseEnter (const MouseEvent& event) override;
    void mouseExit (const MouseEvent& event) override;
    void createPopupBubble();
    void showPopupBubble (int time);
    void setLookAndFeelColours (ValueTree wData);
    String prefix = "";
    String postfix = "";

    FlatButtonLookAndFeel flatLookAndFeel;

public:
    CabbageSlider (ValueTree cAttr, CabbagePluginEditor* _owner);
    ~CabbageSlider();

    void setTextBoxWidth();
    void setSliderVelocity (ValueTree wData);
    void resized();
    void initialiseSlider (ValueTree wData);

    void setTextBoxOrientation (String type, bool textBox);
    void valueTreePropertyChanged (ValueTree& valueTree, const Identifier& prop) override;

    void valueTreeChildAdded (ValueTree&, ValueTree&)override {};
    void valueTreeChildRemoved (ValueTree&, ValueTree&, int) override {}
    void valueTreeChildOrderChanged (ValueTree&, int, int) override {}
    void valueTreeParentChanged (ValueTree&) override {};
    Slider& getSlider()
    {
        return slider;
    };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CabbageSlider)

};



#endif  // CABBAGESLIDER_H_INCLUDED
