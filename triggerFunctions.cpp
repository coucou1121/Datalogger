#include "triggerFunctions.h"

TriggerFunctions::TriggerFunctions()
{
    _valueFunction = 0;

    _traceA = GlobalEnumatedAndExtern::btNone;
    _traceB = GlobalEnumatedAndExtern::btNone;
    _traceC = GlobalEnumatedAndExtern::btNone;
    _traceD = GlobalEnumatedAndExtern::btNone;

    _logicalOperator_Top = GlobalEnumatedAndExtern::opNone;
    _logicalOperator_Middle = GlobalEnumatedAndExtern::opNone;
    _logicalOperator_Bottom = GlobalEnumatedAndExtern::opNone;
}

void TriggerFunctions::displayValue()
{
    qDebug() << "A = " << _traceA << " " << _logicalOperator_Top << " B = " << _traceB;
    qDebug() << "        " << _logicalOperator_Middle ;
    qDebug() << "C = " << _traceC << " " << _logicalOperator_Bottom << " D = " << _traceD;
    qDebug() << "value eq : " << _valueFunction;
    qDebug() << "equation valide : " << this->_checkValideEquation();
    qDebug() << "equation onTrig : " << this->_onTrigStatus;
}

GlobalEnumatedAndExtern::eTracePossible TriggerFunctions::traceA() const
{
    return _traceA;
}

void TriggerFunctions::setTraceA(const GlobalEnumatedAndExtern::eTracePossible &traceA)
{
    _traceA = traceA;
    this->_setValueFunction();
}

GlobalEnumatedAndExtern::eTracePossible TriggerFunctions::traceB() const
{
    return _traceB;
}

void TriggerFunctions::setTraceB(const GlobalEnumatedAndExtern::eTracePossible &traceB)
{
    _traceB = traceB;
    this->_setValueFunction();
}

GlobalEnumatedAndExtern::eTracePossible TriggerFunctions::traceC() const
{
    return _traceC;
}

void TriggerFunctions::setTraceC(const GlobalEnumatedAndExtern::eTracePossible &traceC)
{
    _traceC = traceC;
    this->_setValueFunction();
}

GlobalEnumatedAndExtern::eTracePossible TriggerFunctions::traceD() const
{
    return _traceD;
}

void TriggerFunctions::setTraceD(const GlobalEnumatedAndExtern::eTracePossible &traceD)
{
    _traceD = traceD;
    this->_setValueFunction();
}

GlobalEnumatedAndExtern::eLogicOperator TriggerFunctions::logicalOperator_Top() const
{
    return _logicalOperator_Top;
}

void TriggerFunctions::setLogicalOperator_Top(const GlobalEnumatedAndExtern::eLogicOperator &logicalOperator_Top)
{
    _logicalOperator_Top = logicalOperator_Top;
    this->_setValueFunction();
}

GlobalEnumatedAndExtern::eLogicOperator TriggerFunctions::logicalOperator_Middle() const
{
    return _logicalOperator_Middle;
}

void TriggerFunctions::setLogicalOperator_Middle(const GlobalEnumatedAndExtern::eLogicOperator &logicalOperator_Middle)
{
    _logicalOperator_Middle = logicalOperator_Middle;
    this->_setValueFunction();
}

GlobalEnumatedAndExtern::eLogicOperator TriggerFunctions::logicalOperator_Bottom() const
{
    return _logicalOperator_Bottom;
}

void TriggerFunctions::setLogicalOperator_Bottom(const GlobalEnumatedAndExtern::eLogicOperator &logicalOperator_Bottom)
{
    _logicalOperator_Bottom = logicalOperator_Bottom;
    this->_setValueFunction();
}

bool TriggerFunctions::onTrig(quint8 valueA, quint8 valueB, quint8 valueC, quint8 valueD)
{
    bool onTrig = false;

    quint8 value = 0;

    value = valueA | (valueB << 1) | (valueC << 2) | (valueD  << 3);

    qDebug() << "value : " << value;

    switch (this->_valueFunction)
    {
    case 0:
        onTrig = false;
        break;
    case 1:
        onTrig = value != 0 ? true : false;
        break;
    case 35:
        onTrig = value > 2 ? true : false;
        break;
    case 37:
        onTrig = value != 0 ? true : false;
        break;
    case 41:
        onTrig = value == 1 ? true : false;
        break;
    case 49:
        onTrig = value != 2 ? true : false;
        break;
    case 1123:
        onTrig = value > 6 ? true : false;
        break;
    case 1125:
        onTrig = value > 4 ? true : false;
        break;
    case 1129:
        onTrig = value == 5 ? true : false;
        break;
    case 1137:
        onTrig = (value > 3 && value < 6) || (value > 6) ? true : false;
        break;
    case 1187:
        onTrig = value > 2 ? true : false;
        break;
    case 1189:
        onTrig = value > 0 ? true : false;
        break;
    case 1193:
        onTrig = (value == 1) || (value > 3) ? true : false;
        break;
    case 1201:
        onTrig = value != 2 ? true : false;
        break;
    case 1315:
        onTrig = value == 3 ? true : false;
        break;
    case 1317:
        onTrig = (value > 0) && (value < 4) ? true : false;
        break;
    case 1321:
        onTrig = value == 1 ? true : false;
        break;
    case 1329:
        onTrig = value > 2 ? true : false;
        break;
    case 1571:
        onTrig = (value < 4) || (value > 6) ? true : false;
        break;
    case 1573:
        onTrig = value != 4 ? true : false;
        break;
    case 1577:
        onTrig = (value < 4) || (value == 5) ? true : false;
        break;
    case 1585:
        onTrig = value != 6 ? true : false;
        break;
    case 35939:
        onTrig = value == 15 ? true : false;
        break;
    case 35941:
        onTrig = value > 12 ? true : false;
        break;
    case 35945:
        onTrig = value == 13 ? true : false;
        break;
    case 35953:
        onTrig = ((value > 11) && (value < 14)) || (value > 14) ? true : false;
        break;
    case 36003:
        onTrig = (value == 3) || (value == 7) || (value > 10) ? true : false;
        break;
    case 36005:
        onTrig = ((value > 1) && (value < 4)) ||
                 ((value > 4) && (value < 8)) || (value > 8) ? true : false;
        break;
    case 36009:
        onTrig = (value == 1) || (value == 5) ||
                 (value == 9) || (value > 11) ? true : false;
        break;
    case 36017:
        onTrig = (value < 2) || ((value > 2) && (value < 6)) ||
                 ((value > 6) && (value < 10)) || (value > 10) ? true : false;
        break;
    case 36131:
        onTrig = (value == 3) || (value == 7) || (value == 11) ? true : false;
        break;
    case 36133:
        onTrig = ((value > 0) && (value < 4)) ||
                 ((value > 4) && (value < 8)) || ((value > 8) && (value < 12)) ? true : false;
        break;
    case 36137:
        onTrig = (value == 1) || (value == 5) || (value == 9) ? true : false;
        break;
    case 36145:
        onTrig = (value < 2) || ((value > 2) && (value < 6)) ||
                 ((value > 7) && (value < 10)) || (value == 11)? true : false;
        break;
    case 36387:
        onTrig = (value < 12) || (value == 15) ? true : false;
        break;
    case 36389:
        onTrig = value != 12 ? true : false;
        break;
    case 36393:
        onTrig = (value < 12) || ((value > 12) || (value < 14)) ? true : false;
        break;
    case 36401:
        onTrig = value != 14 ? true : false;
        break;
    case 37987:
        onTrig = (value == 7) || (value == 11) || (value > 14) ? true : false;
        break;
    case 37989:
        onTrig = ((value > 4) && (value < 8)) ||
                 ((value > 8) && (value < 12)) || (value > 13) ? true : false;
        break;
    case 37993:
        onTrig = (value == 5) || (value == 9) || (value == 3) ? true : false;
        break;
    case 38001:
        onTrig = ((value > 4) && (value < 8)) || ((value > 6) && (value < 10)) ||
                 ((value > 10) && (value < 14)) || (value == 15) ? true : false;
        break;
    case 38051:
        onTrig = value > 2 ? true : false;
        break;
    case 38053:
        onTrig = value > 0 ? true : false;
        break;
    case 38057:
        onTrig = ((value > 0) && (value < 2)) || (value > 4) ? true : false;
        break;
    case 38065:
        onTrig = value != 2 ? true : false;
        break;
    case 38179:
        onTrig = value == 3 ? true : false;
        break;
    case 38181:
        onTrig = ((value > 0) && (value < 4)) ? true : false;
        break;
    case 38185:
        onTrig = value == 1 ? true : false;
        break;
    case 38193:
        onTrig = (value < 2) || ((value > 2) && (value < 4)) ? true : false;
        break;
    case 38435:
        onTrig = (value < 4) || (value == 7) || (value == 11) || (value == 15) ? true : false;
        break;
    case 38437:
        onTrig = (value < 1) || (value > 3) ? true : false;
        break;
    case 38441:
        onTrig = (value < 1) || (value == 4) ||
                 ((value > 8) && (value < 13)) ? true : false;
        break;
    case 38449:
        onTrig = (value < 5) || (value > 8) ? true : false;
        break;
    case 42083:
        onTrig = value == 7 ? true : false;
        break;
    case 42085:
        onTrig = ((value > 4) && (value < 8)) ? true : false;
        break;
    case 42089:
        onTrig = value == 5 ? true : false;
        break;
    case 42097:
        onTrig = ((value > 3) && (value < 6)) || (value == 7) ? true : false;
        break;
    case 42147:
        onTrig = ((value > 3) && (value < 8)) ||
                 (value  == 11) || (value == 15) ? true : false;
        break;
    case 42149:
        onTrig = ((value > 0) && (value < 8)) ||
                 ((value > 8) && (value < 12)) || (value > 12) ? true : false;
        break;
    case 42153:
        onTrig = (value == 1) ||
                 ((value > 3) && (value < 8)) || (value == 9) ? true : false;
        break;
    case 42161:
        onTrig = ((value > 0) && (value < 2)) || ((value > 2) && (value < 10)) ||
                 ((value > 10) && (value < 14)) || (value == 15) ? true : false;
        break;
    case 42275:
        onTrig = (value == 3) || (value == 11) || (value == 15) ? true : false;
        break;
    case 42277:
        onTrig = ((value > 1) && (value < 4)) || ((value > 4) && (value < 8)) ||
                 ((value > 8) && (value < 12)) || (value == 15) ? true : false;
        break;
    case 42281:
        onTrig = (value == 1) || (value == 9) || (value == 13) ? true : false;
        break;
    case 42289:
        onTrig = (value < 2) || ((value > 2) && (value < 6)) || ((value > 6) && (value < 10)) ||
                 ((value > 10) && (value < 13)) || ((value > 12) && (value < 14)) ? true : false;
        break;
    case 42531:
        onTrig = ((value < 4) && (value > 6)) ? true : false;
        break;
    case 42533:
        onTrig = value != 4 ? true : false;
        break;
    case 42537:
        onTrig = (value < 4) ||
                 ((value > 4) && (value < 6)) || (value > 8) ? true : false;
        break;
    case 42545:
        onTrig = value != 6 ? true : false;
        break;
    case 50275:
        onTrig = (value == 3) || (value == 7) || (value == 15) ? true : false;
        break;
    case 50277:
        onTrig = ((value > 1) && (value < 4)) ||
                 ((value > 4) && (value < 8)) || (value > 12) ? true : false;
        break;
    case 50281:
        onTrig = (value == 1) || (value == 5) || (value == 13) ? true : false;
        break;
    case 50289:
        onTrig = (value < 2) || ((value > 3) && (value < 6)) || ((value > 7) && (value < 10)) ||
                 ((value > 11) && (value < 14)) || (value == 15) ? true : false;
        break;
    case 50339:
        onTrig = ((value < 8) || (value >10)) ? true : false;
        break;
    case 50341:
        onTrig = value != 8 ? true : false;
        break;
    case 50345:
        onTrig = (value < 8) || (value == 9) || (value > 12) ? true : false;
        break;
    case 50353:
        onTrig = value != 10 ? true : false;
        break;
    case 50467:
        onTrig = value == 11 ? true : false;
        break;
    case 50469:
        onTrig = ((value > 0) && (value < 4)) || (value == 11) ? true : false;
        break;
    case 50473:
        onTrig = value == 9 ? true : false;
        break;
    case 50481:
        onTrig = (value < 2) || (value == 3) || (value == 9) ? true : false;
        break;
    case 50723:
        onTrig = (value == 3) ||
                 ((value > 6) && (value < 12)) || (value = 15) ? true : false;
        break;
    case 50725:
        onTrig = ((value > 0) && (value < 4)) || ((value > 4) && (value < 12)) || (value > 12) ? true : false;
        break;
    case 50729:
        onTrig = (value == 1) || (value == 5) ||
                 ((value > 7) && (value < 12)) || (value == 13) ? true : false;
        break;
    case 50737:
        onTrig = (value < 2) || ((value > 2) && (value < 6)) ||
                 ((value > 6) && (value < 14)) || (value == 15) ? true : false;
        break;
    default:
        onTrig = false;
        break;
    }

    this->_onTrigStatus = onTrig;

    return onTrig;
}

void TriggerFunctions::_setValueFunction()
{
    //set the A value
    if(_traceA != GlobalEnumatedAndExtern::btNone)
    {
        _valueFunction = 1;
    }
    else
    {
        _valueFunction = 0;
    }

    //set the B value
    if(_traceB != GlobalEnumatedAndExtern::btNone)
    {
        _valueFunction |= (1<<5);
    }

    //set the C value
    if(_traceC != GlobalEnumatedAndExtern::btNone)
    {
        _valueFunction |= (1<<10);
    }

    //set the D value
    if(_traceD != GlobalEnumatedAndExtern::btNone)
    {
        _valueFunction |= (1<<15);
    }

    //set the top logical operator value
    if(_logicalOperator_Top != GlobalEnumatedAndExtern::btNone)
    {
        switch (_logicalOperator_Top)
        {
        case GlobalEnumatedAndExtern::opNone:
            break;
        case GlobalEnumatedAndExtern::opAnd:
            _valueFunction = _valueFunction | (1<<1);
            break;
        case GlobalEnumatedAndExtern::opOr:
            _valueFunction = _valueFunction | (1<<2);
            break;
        case GlobalEnumatedAndExtern::opNotAnd:
            _valueFunction = _valueFunction | (1<<3);
            break;
        case GlobalEnumatedAndExtern::opNotOr:
            _valueFunction = _valueFunction | (1<<4);
            break;
        default:
            break;
        }
    }

    //set the top logical operator value
    if(_logicalOperator_Middle != GlobalEnumatedAndExtern::btNone)
    {
        switch (_logicalOperator_Middle)
        {
        case GlobalEnumatedAndExtern::opNone:
            break;
        case GlobalEnumatedAndExtern::opAnd:
            _valueFunction = _valueFunction | (1<<6);
            break;
        case GlobalEnumatedAndExtern::opOr:
            _valueFunction = _valueFunction | (1<<7);
            break;
        case GlobalEnumatedAndExtern::opNotAnd:
            _valueFunction = _valueFunction | (1<<8);
            break;
        case GlobalEnumatedAndExtern::opNotOr:
            _valueFunction = _valueFunction | (1<<9);
            break;
        default:
            break;
        }
    }

    //set the top logical operator value
    if(_logicalOperator_Bottom != GlobalEnumatedAndExtern::btNone)
    {
        switch (_logicalOperator_Bottom)
        {
        case GlobalEnumatedAndExtern::opNone:
            break;
        case GlobalEnumatedAndExtern::opAnd:
            _valueFunction = _valueFunction | (1<<11);
            break;
        case GlobalEnumatedAndExtern::opOr:
            _valueFunction = _valueFunction | (1<<12);
            break;
        case GlobalEnumatedAndExtern::opNotAnd:
            _valueFunction = _valueFunction | (1<<13);
            break;
        case GlobalEnumatedAndExtern::opNotOr:
            _valueFunction = _valueFunction | (1<<14);
            break;
        default:
            break;
        }
    }

    this->_checkValideEquation();
   // this->displayValue();
}

bool TriggerFunctions::_checkValideEquation()
{
    bool valide = true;
    static bool memoValide = valide;

    switch (this->_valueFunction)
    {
    case 0:     case 1:
    case 35:    case 37:    case 41:    case 49:
    case 1123:  case 1125:  case 1129:  case 1137:  case 1187:  case 1189:  case 1193:  case 1201:
    case 1315:  case 1317:  case 1321:  case 1329:  case 1571:  case 1573:  case 1577:  case 1585:
    case 35939: case 35941: case 35945: case 35953: case 36003: case 36005: case 36009: case 36017:
    case 36131: case 36133: case 36137: case 36145: case 36387: case 36389: case 36393: case 36401:
    case 37987: case 37989: case 37993: case 38001: case 38051: case 38053: case 38057: case 38065:
    case 38179: case 38181: case 38185: case 38193: case 38435: case 38437: case 38441: case 38449:
    case 42083: case 42085: case 42089: case 42097: case 42147: case 42149: case 42153: case 42161:
    case 42275: case 42277: case 42281: case 42289: case 42531: case 42533: case 42537: case 42545:
    case 50275: case 50277: case 50281: case 50289: case 50339: case 50341: case 50345: case 50353:
    case 50467: case 50469: case 50473: case 50481: case 50723: case 50725: case 50729: case 50737:
        valide = true;
        break;
    default:
        valide = false;
        break;
    }

    if(valide != memoValide)
    {
        emit _errorWrongEquation(GlobalEnumatedAndExtern::errorWrongEquation, !valide);
        memoValide = valide;
    }

    return valide;
}
