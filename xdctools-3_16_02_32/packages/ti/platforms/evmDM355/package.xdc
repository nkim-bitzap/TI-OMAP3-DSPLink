/*
 *  Copyright (c) 2009 by Texas Instruments and others.
 *  All rights reserved. This program and the accompanying materials
 *  are made available under the terms of the Eclipse Public License v1.0
 *  which accompanies this distribution, and is available at
 *  http://www.eclipse.org/legal/epl-v10.html
 *
 *  Contributors:
 *      Texas Instruments - initial implementation
 *
 * */

requires ti.catalog.arm;
requires xdc.platform [1,0,1];

/*!
 *  ======== ti.platforms.evmDM355 ========
 *  Platform package for the evmDM355 platform.
 *
 *  This package implements the interfaces (xdc.platform.IPlatform) necessary
 *  to build and run executables on the evmDM355 platform.
 *
 *  @a(Throws)
 *  `XDCException` exceptions are thrown for fatal errors. The following error
 *  codes are reported in the exception message:
 *  @p(dlist)                            
 *      -  `ti.platfoms.evmDM355.LINK_TEMPLATE_ERROR`
 *           This error is raised when this platform cannot found the default
 *           linker command template `linkcmd.xdt` in the build target's
 *           package. When a target does not contain this file, the config
 *           parameter `{@link xdc.cfg.Program#linkTemplate}` must be set.
 *  @p
 */
package ti.platforms.evmDM355 [1,0,0] {
    module Platform;
}
/*
 *  @(#) ti.platforms.evmDM355; 1, 0, 0,196; 12-9-2009 17:22:06; /db/ztree/library/trees/platform/platform-k27x/src/
 */

