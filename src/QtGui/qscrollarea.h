// Copyright (c) 2012, Artur Adib
// All rights reserved.
//
// Author(s): Artur Adib <aadib@mozilla.com>
//
// You may use this file under the terms of the New BSD license as follows:
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of Artur Adib nor the
//       names of contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
// ARE DISCLAIMED. IN NO EVENT SHALL ARTUR ADIB BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF 
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef QSCROLLAREAWRAP_H
#define QSCROLLAREAWRAP_H

#include <node.h>
#include <QScrollArea>

//
// QScrollAreaWrap()
//
class QScrollAreaWrap : public node::ObjectWrap {
 public:
  static void Initialize(v8::Handle<v8::Object> target);
  QScrollArea* GetWrapped() const { return q_; };

 private:
  QScrollAreaWrap(_NAN_METHOD_ARGS);
  ~QScrollAreaWrap();
  static v8::Persistent<v8::Function> constructor;
  static v8::Handle<v8::Value> New(_NAN_METHOD_ARGS);

  // Generic QWidget methods
  static v8::Handle<v8::Value> Resize(_NAN_METHOD_ARGS);
  static v8::Handle<v8::Value> Show(_NAN_METHOD_ARGS);
  static v8::Handle<v8::Value> Close(_NAN_METHOD_ARGS);
  static v8::Handle<v8::Value> Size(_NAN_METHOD_ARGS);
  static v8::Handle<v8::Value> Width(_NAN_METHOD_ARGS);
  static v8::Handle<v8::Value> Height(_NAN_METHOD_ARGS);
  static v8::Handle<v8::Value> ObjectName(_NAN_METHOD_ARGS);
  static v8::Handle<v8::Value> SetObjectName(_NAN_METHOD_ARGS);
  static v8::Handle<v8::Value> Parent(_NAN_METHOD_ARGS);
  static v8::Handle<v8::Value> Update(_NAN_METHOD_ARGS);
  static v8::Handle<v8::Value> SetFocusPolicy(_NAN_METHOD_ARGS);
  static v8::Handle<v8::Value> Move(_NAN_METHOD_ARGS);
  static v8::Handle<v8::Value> X(_NAN_METHOD_ARGS);
  static v8::Handle<v8::Value> Y(_NAN_METHOD_ARGS);

  // QScrollArea-specific methods
  static v8::Handle<v8::Value> SetWidget(_NAN_METHOD_ARGS);
  static v8::Handle<v8::Value> Widget(_NAN_METHOD_ARGS);
  static v8::Handle<v8::Value> SetFrameShape(_NAN_METHOD_ARGS);
  static v8::Handle<v8::Value> 
    SetVerticalScrollBarPolicy(_NAN_METHOD_ARGS);
  static v8::Handle<v8::Value> 
    SetHorizontalScrollBarPolicy(_NAN_METHOD_ARGS);
  static v8::Handle<v8::Value> VerticalScrollBar(_NAN_METHOD_ARGS);
  static v8::Handle<v8::Value> HorizontalScrollBar(_NAN_METHOD_ARGS);

  // Wrapped object
  QScrollArea* q_;
};

#endif
