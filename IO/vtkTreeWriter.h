/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkTreeWriter.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkTreeWriter - write vtk table data to a file
// .SECTION Description
// vtkTreeWriter is a source object that writes ASCII or binary 
// table data files in vtk format. See text for format details.
// .SECTION Caveats
// Binary files written on one system may not be readable on other systems.

#ifndef __vtkTreeWriter_h
#define __vtkTreeWriter_h

#include "vtkDataWriter.h"

class vtkTree;

class VTK_IO_EXPORT vtkTreeWriter : public vtkDataWriter
{
public:
  static vtkTreeWriter *New();
  vtkTypeRevisionMacro(vtkTreeWriter,vtkDataWriter);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Get the input to this writer.
  vtkTree* GetInput();
  vtkTree* GetInput(int port);

protected:
  vtkTreeWriter() {};
  ~vtkTreeWriter() {};

  void WriteData();

  virtual int FillInputPortInformation(int port, vtkInformation *info);

private:
  vtkTreeWriter(const vtkTreeWriter&);  // Not implemented.
  void operator=(const vtkTreeWriter&);  // Not implemented.

  void WriteArcs(ostream& Stream, vtkTree* Tree, vtkIdType Node);
};

#endif
