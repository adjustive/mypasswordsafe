#ifndef SAFEDRAGOBJECT_HPP
#define SAFEDRAGOBJECT_HPP

#include <qdragobject.h>
#include <qptrlist.h>
#include <qdom.h>
#include <qstring.h>

class SafeItem;

class SafeDragObject: public QDragObject
{
  Q_OBJECT;

public:
  SafeDragObject(QWidget *src = NULL);
  virtual ~SafeDragObject();

  void addItem(SafeItem *);

  virtual const char *format(int i = 0) const;
  virtual bool provides(const char *mime_type) const;
  virtual QByteArray encodedData(const char *mime_type) const;
  static bool canDecode(const QMimeSource *src);
  static bool decode(const QMimeSource *src, QDomDocument &xml);

private:
  QDomDocument m_xml;
  QString m_text;

  enum State { Nothing, Single, Multiple };
  State m_state;
};

#endif
