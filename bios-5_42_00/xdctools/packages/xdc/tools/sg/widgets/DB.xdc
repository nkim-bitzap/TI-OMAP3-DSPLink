/* 
 *Copyright (c) 2008 Texas Instruments and others.
 *  All rights reserved. This program and the accompanying materials
 *  are made available under the terms of the Eclipse Public License v1.0
 *  which accompanies this distribution, and is available at
 *  http://www.eclipse.org/legal/epl-v10.html
 * 
 *  Contributors:
 *      Texas Instruments - initial implementation
 *
 * */
metaonly module DB {
instance:
    create();
    Any getPath();
    Void setPath(String path[]);

    Any getUnits(String childOf);
}
/*
 *  @(#) xdc.tools.sg.widgets; 1,0,0,219; 8-27-2012 11:53:54; /db/ztree/library/trees/xdctools/xdctools-f15x/src/
 */

