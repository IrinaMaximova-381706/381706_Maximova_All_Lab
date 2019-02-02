#include "Polynomial.h"

TPolynom::TPolynom(int _n)
{
  if (_n <= 0)
    throw MyException("Error kolvo");
  n = _n;
  size = 0;
  start = 0;
}// ---------------------------------------------------------------------------

TPolynom::TPolynom(TPolynom &p)
{
  n = p.n;
  size = p.size;
  if (p.start == 0)
    start = 0;
  else
  {
    start = new TMonom(*p.start);
    TMonom* a = p.start;
    TMonom* b = start;
    while (a->GetNext() != 0)
    {
      b->SetNext(new TMonom(*(a->GetNext())));
      b = b->GetNext();
      a = a->GetNext();
    }
    b->SetNext(NULL);
  }
}// ---------------------------------------------------------------------------

TPolynom::~TPolynom() 
{}// ---------------------------------------------------------------------------

int TPolynom::GetSize()
{
  return size;
}// ---------------------------------------------------------------------------

TMonom* TPolynom::GetStart()
{
  return start;
}// ---------------------------------------------------------------------------

TPolynom TPolynom::operator+(TPolynom &p)
{
  if (this->n != p.n)
    throw MyException("Different size");
  TPolynom rez(n);
  TMonom *i1 = start, *i2 = p.start, *i = rez.start;
  while ((i1 != 0) && (i2 != 0))
  {
    TMonom *t;
    if ((*i1) == (*i2))
    {
      TMonom k = (*i1);
      k += (*i2);
      t = new TMonom(k);
      if (t->GetC() == 0)
        continue;
      i1 = i1->GetNext();
      i2 = i2->GetNext();
    }
    else if ((*i1) < (*i2))
    {
      t = new TMonom((*i2));
      if (t->GetC() == 0)
        continue;
      i2 = i2->GetNext();
    }
    else if ((*i1) > (*i2))
    {
      t = new TMonom((*i1));
      if (t->GetC() == 0)
        continue;
      i1 = i1->GetNext();
    }
    if (i == 0)
    {
      i = t;
      rez.start = t;
      rez.size++;
    }
    else
    {
      i->SetNext(t);
      rez.size++;
      i = i->GetNext();
    }
  }
  if (i1 == 0)
    i1 = i2;
  while (i1 != 0)
  {
    if (i1->GetC() == 0)
      continue;
    i->SetNext(new TMonom(*i1));
    i1 = i1->GetNext();
    rez.size++;
    i = i->GetNext();
  }
  return rez;
}// ---------------------------------------------------------------------------

TPolynom TPolynom::operator-(TPolynom &p)
{
  if (this->n != p.n)
    throw MyException("Different size");
  TPolynom rez(n);
  TMonom *i1 = start, *i2 = p.start, *i = rez.start;
  while ((i1 != 0) && (i2 != 0))
  {
    TMonom *t;
    if ((*i1) == (*i2))
    {
      TMonom k = (*i1);
      k -= (*i2);
      t = new TMonom(k);
      i1 = i1->GetNext();
      i2 = i2->GetNext();
    }
    else if ((*i1) < (*i2))
    {
      t = new TMonom((*i2));
      if (t->GetC() == 0)
        continue;
      t->SetC(t->GetC() * (-1));
      i2 = i2->GetNext();
    }
    else if ((*i1) > (*i2))
    {
      t = new TMonom((*i1));
      if (t->GetC() == 0)
        continue;
      i1 = i1->GetNext();
    }
    if (t->GetC() == 0)
      continue;
    if (i == 0)
    {
      i = t;
      rez.start = t;
      rez.size++;
    }
    else
    {
      i->SetNext(t);
      rez.size++;
      i = i->GetNext();
    }
  }
  while (i1 != 0)
  {
    if (i1->GetC() == 0)
      continue;
    i->SetNext(new TMonom(*i1));
    i1 = i1->GetNext();
    rez.size++;
    i = i->GetNext();
  }
  while (i2 != 0)
  {
    if (i2->GetC() == 0)
      continue;
    TMonom t(*i2);
    t.SetC(t.GetC() * (-1));
    i->SetNext(&t);
    i2 = i2->GetNext();
    rez.size++;
    i = i->GetNext();
  }
  return rez;
}// ---------------------------------------------------------------------------

TPolynom& TPolynom::operator=(const TPolynom &p)
{
  if (*this == p)
    return *this;
  if (this->n != p.n)
    throw MyException("Different size");
  else
  {
    size = p.size;
    TMonom *buf1 = start, *buf2 = start;
    while (buf1 != 0)
    {
      buf1 = buf1->GetNext();
      delete buf2;
      buf2 = buf1;
    }
    buf1 = p.start->GetNext();
    buf2 = new TMonom(*p.start);
    start = buf2;
    while (buf1 != 0)
    {
      buf2->SetNext(new TMonom(*buf1));
      buf2 = buf2->GetNext();
      buf1 = buf1->GetNext();
    }
    return *this;
  }
}// ---------------------------------------------------------------------------

bool TPolynom::operator==(const TPolynom &p)
{
  if (this->n != p.n)
    throw MyException("Different size");
  if (this->size != p.size)
    return false;
  TMonom* a = start;
  TMonom* b = p.start;
  while (a != 0)
  {
    if (!(*a == *b))
      return false;
    if (a->GetC() != b->GetC())
      return false;
    a = a->GetNext();
    b = b->GetNext();
  }
  return true;
}// ---------------------------------------------------------------------------

TPolynom TPolynom::operator*(TPolynom &p)
{
  if (this->n != p.n)
    throw MyException("Different size");
  TPolynom rez(n);
  TMonom *_st = start;
  TMonom *_pst = p.start;
  while (_st != 0)
  {
    if (_st->GetC() == 0)
      continue;
    while (_pst != 0)
    {
      if (_pst->GetC() == 0)
        continue;
      TMonom k = (*_st);
      k *= (*_pst);
      TMonom* f = new TMonom(k);
      f->SetNext(NULL);
      rez += *f;
      _pst = _pst->GetNext();
    }
    _st = _st->GetNext();
    _pst = p.start;
  }
  return rez;
}// ---------------------------------------------------------------------------

TPolynom &TPolynom::operator+=(TMonom &m)
{
  if (this->n != m.GetN())
    throw MyException("Different size");
  if (m.GetC() == 0)
    return *this;
  if (start == 0)
    start = new TMonom(m);
  else
  {
    TMonom *_start, *_end;
    _start = start;
    _end = start->GetNext();
    if (*start < m)
    {
      TMonom* tmp = new TMonom(m);
      tmp->SetNext(start);
      start = tmp;
    }
    else if (*start == m)
    {
      *start += m;
      if (start->GetC() == 0)
      {
        TMonom* temp = start->GetNext();
        delete[] start;
        start = temp;
      }
    }
    else
    {
      while (_end != 0)
      {
        if (*_end == m)
        {
          *_end += m;
          if (_end->GetC() == 0)
          {
            start->SetNext(_end->GetNext());
            delete[] _end;
          }
         // size++;
          return *this;
        }
        if (*_end < m)
        {
          TMonom* tmp = new TMonom(m);
          _start->SetNext(tmp);
          tmp->SetNext(_end);
          size++;
          return *this;
        }
        _start = _end;
        _end = _end->GetNext();
      }
      _start->SetNext(new TMonom(m));
    }
  }
  size++;
  return *this;
}// ---------------------------------------------------------------------------

TPolynom &TPolynom::operator-=(TMonom &m)
{
  if (this->n != m.GetN())
    throw MyException("Different size");
  if (m.GetC() == 0)
    return *this;
  m.SetC(m.GetC() * (-1));
  if (start == 0)
    start = new TMonom(m);
  else
  {
    TMonom *_start, *_end;
    _start = start;
    _end = start->GetNext();
    if (*start < m)
    {
      TMonom* tmp = new TMonom(m);
      tmp->SetNext(start);
      start = tmp;
    }
    else if (*start == m)
    {
      *start -= m;
      if (start->GetC() == 0)
      {
        TMonom* temp = start->GetNext();
        delete[] start;
        start = temp;
      }
    }
    else
    {
      while (_end != 0)
      {
        if (*_end == m)
        {
          *_end -= m;
          if (_end->GetC() == 0)
          {
            start->SetNext(_end->GetNext());
            delete[] _end;
          }
          size++;
          return *this;
        }
        if (*_end < m)
        {
          TMonom* tmp = new TMonom(m);
          _start->SetNext(tmp);
          tmp->SetNext(_end);
          size++;
          return *this;
        }
        _start = _end;
        _end = _end->GetNext();
      }
      _start->SetNext(new TMonom(m));
    }
  }
  size++;
  return *this;
}// ---------------------------------------------------------------------------

ostream& operator<<(ostream& _s, TPolynom& Tm)
{
  TMonom *tmp = Tm.start;
  if (tmp != 0)
  {
    _s << *tmp;
    tmp = tmp->GetNext();
  }
  while (tmp != 0)
  {
    if (tmp->GetC() != 0)
      _s << " + " << *tmp;
    tmp = tmp->GetNext();
  }
  return _s;
}// ---------------------------------------------------------------------------
