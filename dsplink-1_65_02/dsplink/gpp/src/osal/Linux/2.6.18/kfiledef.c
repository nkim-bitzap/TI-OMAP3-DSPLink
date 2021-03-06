/** ============================================================================
 *  @file   kfiledef.c
 *
 *  @path   $(DSPLINK)/gpp/src/osal/Linux/2.6.18/
 *
 *  @desc   Implementation of sub-component KFILE.
 *
 *  @ver    1.65.02.09
 *  ============================================================================
 *  Copyright (C) 2002-2012, Texas Instruments Incorporated - http://www.ti.com/
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation version 2.
 *  
 *  This program is distributed "as is" WITHOUT ANY WARRANTY of any kind,
 *  whether express or implied; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 *  General Public License for more details.
 *  ============================================================================
 */

/*  ----------------------------------- OS Specific Headers         */
#include <linux/version.h>

/* support for original antique kernels (2.6.xx) removed */
#include <generated/autoconf.h>

#include <linux/spinlock.h>
#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/fs.h>
#include <asm/segment.h>
#include <asm/uaccess.h>
#include <asm/unistd.h>

/*  ----------------------------------- DSP/BIOS Link               */
#include <dsplink.h>
#include <_dsplink.h>

/*  ----------------------------------- Trace & Debug               */
#include <_trace.h>
#include <trc.h>
#include <print.h>

/*  ----------------------------------- OSAL Headers                */
#include <osal.h>

/*  ----------------------------------- Generic Function            */
#include<gen_utils.h>


#if defined (__cplusplus)
extern "C" {
#endif /* defined (__cplusplus) */


/** ============================================================================
 *  @macro  COMPONENT_ID
 *
 *  @desc   Identifier for sub-component.
 *  ============================================================================
 */
#define  COMPONENT_ID       ID_OSAL_KFILE


/** ============================================================================
 *  @macro  SET_FAILURE_REASON
 *
 *  @desc   Sets failure reason.
 *  ============================================================================
 */
#if defined (DDSP_DEBUG)
#define SET_FAILURE_REASON   TRC_SetReason (status, FID_C_OSAL_KFILE, __LINE__)
#else
#define SET_FAILURE_REASON
#endif /* if defined (DDSP_DEBUG) */


/** ============================================================================
 *  @macro  SEEK_SET
 *
 *  @desc   Seek from beginning.
 *  ============================================================================
 */
#define SEEK_SET        0

/** ============================================================================
 *  @macro  SEEK_CUR
 *
 *  @desc   Seek from current location.
 *  ============================================================================
 */
#define SEEK_CUR        1

/** ============================================================================
 *  @macro  SEEK_END
 *
 *  @desc   Seek from end of file.
 *  ============================================================================
 */
#define SEEK_END        2


/** ============================================================================
 *  @name   KFILEDEF_Object_tag
 *
 *  @desc   This is a forward declared type in kfile.h.
 *
 *  @field  signature
 *              Signature of the KFILE object.
 *  @field  fileDesc
 *              File descriptor.
 *  @field  fileName
 *              File name.
 *  @field  isOpen
 *              Flag to indicate that file is open.
 *  @field  size
 *              Size of the file.
 *  @field  curPos
 *              Current file position indicator.
 *
 *  @see    None
 *  ============================================================================
 */
typedef struct KFILEDEF_Object_tag {
    Uint32        signature ;
    struct file * fileDesc  ;
    Pstr          fileName  ;
    Uint32        size      ;
    Uint32        curPos    ;
} KFILEDEF_Object;


/** ============================================================================
 *  @func   KFILEDEF_Open
 *
 *  @desc   Opens a file specified by name of file.
 *
 *  @modif  None
 *  ============================================================================
 */
EXPORT_API
DSP_STATUS
KFILEDEF_Open (IN CONST FileName       fileName,
               IN CONST Char8 *        mode,
               OUT      Void **        fileHandlePtr) ;

/** ============================================================================
 *  @func   KFILEDEF_Close
 *
 *  @desc   Closes a file handle.
 *
 *  @modif  None
 *  ============================================================================
 */
EXPORT_API
DSP_STATUS
KFILEDEF_Close (IN Void * fileHandle) ;

/** ============================================================================
 *  @func   KFILEDEF_Read
 *
 *  @desc   Reads a specified number of items of specified size
 *          bytes from file to a buffer.
 *
 *  @modif  None
 *  ============================================================================
 */
EXPORT_API
DSP_STATUS
KFILEDEF_Read (IN OUT  Char8 *       buffer,
               IN      Uint32        size,
               IN      Uint32        count,
               IN      Void *        fileHandle) ;

/** ============================================================================
 *  @func   KFILEDEF_Seek
 *
 *  @desc   Repositions the file pointer according to specified arguments.
 *
 *  @modif  None
 *  ============================================================================
 */
EXPORT_API
DSP_STATUS
KFILEDEF_Seek (IN  Void *          fileHandle,
               IN  Int32           offset,
               IN  KFILE_FileSeek  origin) ;

/** ============================================================================
 *  @func   KFILEDEF_Tell
 *
 *  @desc   Returns the current file pointer position for the specified
 *          file handle.
 *
 *  @modif  None
 *  ============================================================================
 */
EXPORT_API
DSP_STATUS
KFILEDEF_Tell (IN  Void *        fileHandle,
               OUT Int32 *       pos) ;

/** ============================================================================
 *  @name   KFILEDEF_Interface
 *
 *  @desc   Definition of the interface table for KFILEPSEUDO module.
 *  ============================================================================
 */

KFILE_Interface KFILEDEF_Interface =
{
  &KFILEDEF_Open,
  &KFILEDEF_Close,
  &KFILEDEF_Read,
  &KFILEDEF_Seek,
  &KFILEDEF_Tell,
  NULL
};

/*******************************************************************************
  @func  KFILEDEF_Open
  @desc  Opens a file specified by name of file.
  @note  Slight changes for kernel versions > 4.14
*******************************************************************************/

EXPORT_API DSP_STATUS KFILEDEF_Open(IN CONST FileName fileName,
                                    IN CONST Char8 *mode,
                                    OUT Void **fileHandlePtr)
{
  DSP_STATUS status = DSP_SOK;
  Uint32 length = 0;
  Bool fdErr = FALSE;

  struct file *fd = NULL;
  mm_segment_t fs;
  KFILEDEF_Object *fileObj = NULL;

  TRC_3ENTER("KFILEDEF_Open ()", fileName, mode, fileHandlePtr);

  DBC_Require(fileName != NULL);
  DBC_Require(mode != NULL);
  DBC_Require(fileHandlePtr != NULL);

  if ((fileName == NULL) || (fileHandlePtr == NULL)
      || (mode == NULL) || (mode[0] != 'r'))
  {
    status = DSP_EINVALIDARG;
    SET_FAILURE_REASON;
  }
  else {
    *fileHandlePtr = NULL;

    status = GEN_Strlen(fileName, &length);

    if (DSP_FAILED(status)) {
      SET_FAILURE_REASON;
    }
    else if (length == 0) {
      status = DSP_EINVALIDARG;
      SET_FAILURE_REASON;
    }
    else {
      status = MEM_Alloc((Void **) &fileObj,
                         sizeof (KFILEDEF_Object),
                         MEM_DEFAULT);
    }
  }

  if (DSP_SUCCEEDED(status)) {

    fs = get_fs();
    set_fs(KERNEL_DS);

    /* Open the file. Initialize the file object after validating the object
       returned by kernel. The third argument is ignored unless creating
       files */
    fd = filp_open(fileName, O_RDONLY, 0);

    if (IS_ERR(fd) || fd == NULL || fd->f_op == NULL)
    {
      TRC_2PRINT(TRC_LEVEL5,
                 "*** error in '%s': invalid file descriptor (0x%x)\n",
                 __FUNCTION__, fd);

      fdErr = TRUE;
    }
    else {
      /* since kernel version 4.14 the 'read_iter' function can be used as
         alternative to 'read', thus, we need to check both */
      if (fd->f_op->read == NULL && fd->f_op->read_iter == NULL)
      {
        TRC_1PRINT(TRC_LEVEL5,
                   "*** error in '%s': no 'read' function found in "
                   "the file descriptor interface\n", __FUNCTION__);

        fdErr = TRUE;
      }
    }

    if (fdErr == TRUE) {
      status = DSP_EFILE;
      SET_FAILURE_REASON;
    }
    else {
      fileObj->fileDesc = fd;
      fileObj->fileName = fileName;
      fileObj->curPos = 0;

      /* get the file size  */
      fd->f_pos = 0u;
      *fileHandlePtr = (Void *)fileObj;

      /* Changes for yaffs2 support */
      if (fd->f_op->llseek != NULL) {
        fileObj->size = fd->f_op->llseek(fd, 0, SEEK_END);
        fd->f_op->llseek(fd, 0, SEEK_SET);
      }
      else {
        fileObj->size = default_llseek(fd, 0, SEEK_END);
        default_llseek(fd, 0, SEEK_SET);
      }
    }

    /* If the function call failed then free the object allocated before */
    if (DSP_FAILED(status)) {
      FREE_PTR (*fileHandlePtr);
      *fileHandlePtr = NULL;
    }

    set_fs(fs);
  }
  else {
    status = DSP_EFILE;
    SET_FAILURE_REASON;
  }

  DBC_Ensure(DSP_SUCCEEDED(status)
             || (DSP_FAILED(status)
                 && (fileHandlePtr != NULL)
                 && (*fileHandlePtr == NULL)));

  TRC_1LEAVE ("KFILEDEF_Open", status);
  return status;
}

/*******************************************************************************
  @func  KFILEDEF_Close
  @desc  Closes a file handle
*******************************************************************************/

EXPORT_API DSP_STATUS KFILEDEF_Close(IN Void *fileHandle)
{
  DSP_STATUS status = DSP_SOK;
  mm_segment_t fs;
  KFILEDEF_Object *fileObj = NULL;

  TRC_1ENTER("KFILEDEF_Close", fileHandle);

  DBC_Require(fileHandle != NULL);

  if (fileHandle == NULL) {
    status = DSP_EFILE;
    SET_FAILURE_REASON;
  }
  else {
    fileObj = (KFILEDEF_Object *) fileHandle;

    fs = get_fs();
    set_fs (KERNEL_DS);

    filp_close (fileObj->fileDesc, NULL);
    set_fs(fs);

    FREE_PTR(fileObj);
  }

  DBC_Ensure((DSP_SUCCEEDED(status) && (fileObj == NULL))
          || (DSP_FAILED(status)));

  TRC_1LEAVE("KFILEDEF_Close", status);
  return status;
}

/*******************************************************************************
  @func  KFILEDEF_Read
  @desc  Reads a specified number of items of specified size
         bytes from file to a buffer
*******************************************************************************/

EXPORT_API DSP_STATUS KFILEDEF_Read(IN OUT Char8 *buffer,
                                    IN Uint32 size,
                                    IN Uint32 count,
                                    IN Void *fileHandle)
{
  DSP_STATUS status = DSP_SOK;
  Int32 bytesRead = 0;
  mm_segment_t fs;
  KFILEDEF_Object *fileObj = NULL;

  TRC_4ENTER ("KFILEDEF_Read", buffer, size, count, fileHandle);

  DBC_Require(fileHandle != NULL);
  DBC_Require(buffer != NULL);

  if (buffer == NULL) {
    status = DSP_EINVALIDARG;
    SET_FAILURE_REASON;
  }
  else if ((size != 0) && (count != 0)) {
    fileObj = (KFILEDEF_Object *) fileHandle;

    if ((fileObj->curPos + (size * count)) > fileObj->size) {
      status = DSP_ERANGE;
      SET_FAILURE_REASON;
    }
    else {
      DBC_Require(fileObj->fileDesc->f_op->read != NULL
               || fileObj->fileDesc->f_op->read_iter != NULL);

      fs = get_fs();
      set_fs (KERNEL_DS);

      /* NKim, instead of triggering the 'read' or 'read_iter' functions
         directly, we now employ 'vfs_read' that selects the proper
         function for us upon availability in the specified descriptor */
      bytesRead = vfs_read(fileObj->fileDesc,
                           buffer,
                           size *count,
                           &(fileObj->fileDesc->f_pos));

      set_fs(fs);

      if (bytesRead >= 0) {
        fileObj->curPos += bytesRead;
        DBC_Assert((bytesRead / size) == (Uint32) count);
      }
      else status = DSP_EFILE;
    }
  }

  TRC_1LEAVE("KFILEDEF_Read", status);
  return status;
}

/** ============================================================================
 *  @func   KFILEDEF_Seek
 *
 *  @desc   Repositions the file pointer according to specified arguments.
 *
 *  @modif  None
 *  ============================================================================
 */
EXPORT_API
DSP_STATUS
KFILEDEF_Seek (IN  Void *          fileHandle,
               IN  Int32           offset,
               IN  KFILE_FileSeek  origin)
{
    DSP_STATUS    status   = DSP_SOK ;
    struct file * fileDesc = NULL    ;
    mm_segment_t  fs                 ;
    KFILEDEF_Object * fileObj = NULL ;

    TRC_3ENTER ("KFILEDEF_Seek", fileHandle, offset, origin) ;

    DBC_Require (fileHandle != NULL) ;
    DBC_Require (   (origin == KFILE_SeekSet)
                 || (origin == KFILE_SeekCur)
                 || (origin == KFILE_SeekEnd)) ;

    if (fileHandle == NULL) {
        status = DSP_EFILE ;
        SET_FAILURE_REASON ;
    }
    else {
        fileObj = (KFILEDEF_Object *) fileHandle ;
        fs = get_fs () ;
        set_fs (get_ds()) ;

        fileDesc = fileObj->fileDesc ; ;
        switch (origin)
        {
        case KFILE_SeekSet:
            if (   (offset < 0)
                || (offset > fileObj->size)) {
                status = DSP_ERANGE ;
                SET_FAILURE_REASON ;
            }
            else {
	            /* Changes for yaffs2 support */
                if (fileDesc->f_op->llseek != NULL) {
                    fileObj->curPos = fileDesc->f_op->llseek (fileDesc,
                                                              offset,
                                                              SEEK_SET) ;
                }
                else {
                    fileObj->curPos = default_llseek (fileDesc,
                                                      offset,
                                                      SEEK_SET) ;
                }
            }
	        break ;

        case KFILE_SeekCur:
            if (   ((fileObj->curPos + offset) > fileObj->size)
                || ((fileObj->curPos + offset) < 0)) {
                status = DSP_ERANGE ;
                SET_FAILURE_REASON ;
            }
            else {
    	        /* Changes for yaffs2 support */
                if (fileDesc->f_op->llseek != NULL) {
                    fileObj->curPos = fileDesc->f_op->llseek (fileDesc,
                                                              offset,
                                                              SEEK_CUR) ;
                }
                else {
                    fileObj->curPos = default_llseek (fileDesc,
                                                      offset,
                                                      SEEK_CUR) ;
                }                                      
            }
            break ;

        case KFILE_SeekEnd:
            /*  ----------------------------------------------------------------
             *  A negative offset indicates offset from the end of file.
             *  Check that the specified offset is not beyond
             *  the bounds of the file.
             *  ----------------------------------------------------------------
             */
            if (   (-offset < 0)
                || (-offset > fileObj->size)) {
                status = DSP_ERANGE ;
                SET_FAILURE_REASON ;
            }
            else {
	            /* Changes for yaffs2 support */
                if (fileDesc->f_op->llseek != NULL) {
                    fileObj->curPos = fileDesc->f_op->llseek (fileDesc,
                                                              offset,
                                                              SEEK_END) ;
                }
                else {
                    fileObj->curPos = default_llseek (fileDesc,
                                                      offset,
                                                      SEEK_END) ;
                }
            }
            break ;

        default:
            TRC_0PRINT (TRC_LEVEL7, "Invalid origin specified\n") ;
            status = DSP_EINVALIDARG ;
            SET_FAILURE_REASON ;
            break ;
        }
        set_fs (fs) ;
    }

    TRC_1LEAVE ("KFILEDEF_Seek", status) ;

    return status ;
}


/** ============================================================================
 *  @func   KFILEDEF_Tell
 *
 *  @desc   Returns the current file pointer position for the specified
 *          file handle.
 *
 *  @modif  None
 *  ============================================================================
 */
EXPORT_API
DSP_STATUS
KFILEDEF_Tell (IN  Void *        fileHandle,
               OUT Int32 *       pos)
{
    DSP_STATUS   status = DSP_SOK ;
    KFILEDEF_Object * fileObj = NULL ;

    TRC_2ENTER ("KFILEDEF_Tell", fileObj, pos) ;

    DBC_Require (fileObj != NULL) ;
    DBC_Require (pos != NULL) ;

    if (pos == NULL) {
        status = DSP_EINVALIDARG ;
        SET_FAILURE_REASON ;
    }
    else {
        fileObj = (KFILEDEF_Object *) fileHandle ;
        *pos = fileObj->curPos ;
        DBC_Assert (*pos == fileObj->fileDesc->f_pos) ;
    }

    DBC_Ensure (   (DSP_SUCCEEDED (status) && (pos != NULL) && (*pos >= 0))
                || (DSP_FAILED (status))) ;

    TRC_1LEAVE ("KFILEDEF_Tell", status) ;

    return status ;
}


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */
