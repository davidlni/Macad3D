﻿using System.Windows.Data;
using System.Windows.Input;
using Macad.Presentation;

namespace Macad.Interaction
{
    public partial class ValueHudElement : HudElement
    {
        public string Label
        {
            get { return _Label; }
            set
            {
                if (_Label != value)
                {
                    _Label = value;
                    RaisePropertyChanged();
                }
            }
        }

        //--------------------------------------------------------------------------------------------------

        public double Value
        {
            get { return _Value; }
            set
            {
                if (_Value != value)
                {
                    _Value = value;
                    RaisePropertyChanged();
                    IsInKeyboardMode = false;
                }
            }
        }

        //--------------------------------------------------------------------------------------------------

        public ValueUnits Units
        {
            get { return _Units; }
            set
            {
                if (_Units != value)
                {
                    _Units = value;
                    RaisePropertyChanged();
                }
            }
        }

        //--------------------------------------------------------------------------------------------------

        public bool IsInKeyboardMode
        {
            get { return _IsInKeyboardMode; }
            set
            {
                if (_IsInKeyboardMode != value)
                {
                    _IsInKeyboardMode = value;
                    RaisePropertyChanged();
                }
            }
        }

        //--------------------------------------------------------------------------------------------------
        
        string _Label;
        double _Value;
        ValueUnits _Units;
        bool _IsInKeyboardMode;

        //--------------------------------------------------------------------------------------------------

        public override void SimulatedKeyDown(KeyEventArgs eventArgs)
        {
            ValueEditBox.SimulatedKeyDown(eventArgs, !IsInKeyboardMode);
            if (eventArgs.Handled)
            {
                IsInKeyboardMode = true;
            }
        }

        //--------------------------------------------------------------------------------------------------

        public delegate void ValueEnteredEvent(ValueHudElement hudElement, double newValue);

        public event ValueEnteredEvent ValueEntered;

        //--------------------------------------------------------------------------------------------------

        public ValueHudElement()
        {
            InitializeComponent();
            SourceUpdated += _OnSourceUpdated;
        }

        //--------------------------------------------------------------------------------------------------

        void _OnSourceUpdated(object sender, DataTransferEventArgs eventArgs)
        {
            if (eventArgs.TargetObject == ValueEditBox)
            {
                IsInKeyboardMode = false;
                ValueEntered?.Invoke(this, Value);
            }
        }
        
        //--------------------------------------------------------------------------------------------------

        public void SetValue(double value)
        {
            Value = value;
        }

        //--------------------------------------------------------------------------------------------------

    }
}
