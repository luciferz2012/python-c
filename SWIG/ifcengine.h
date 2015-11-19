//
//  Author:  Peter Bonsma
//  $Date: 1999-12-31 23:59:59 +0000 (Wed, 31 Jan 1999) $
//  $Revision: 3999 $
//  Project: IFC Engine DLL
//
//  In case of use of the DLL:
//  be aware of license fee for use of this DLL when used commercially
//  more info for commercial use:  peter.bonsma@rdf.bg
//

#pragma once

#include <stdint.h>

#if defined(WIN64) || defined(__LP64__)
	#define int int64_t
#else
	#define int int32_t
#endif


#ifdef _WINDOWS
	#ifdef _USRDLL
		#define DECL __declspec(dllexport) 
	#else
		#define DECL __declspec(dllimport) 
	#endif
	#define STDC __stdcall
#else
	#define DECL /*nothing*/
	#define STDC /*nothing*/
//	char* itoa(int value, char* result, int base);
#endif


#ifdef __cplusplus
    extern "C" {
#endif


#define		sdaiADB					1
#define		sdaiAGGR				sdaiADB + 1
#define		sdaiBINARY				sdaiAGGR + 1
#define		sdaiBOOLEAN				sdaiBINARY + 1
#define		sdaiENUM				sdaiBOOLEAN + 1
#define		sdaiINSTANCE			sdaiENUM + 1
#define		sdaiINTEGER				sdaiINSTANCE + 1
#define		sdaiLOGICAL				sdaiINTEGER + 1
#define		sdaiREAL				sdaiLOGICAL + 1
#define		sdaiSTRING				sdaiREAL + 1
#define		sdaiUNICODE				sdaiSTRING + 1
#define		sdaiEXPRESSSTRING		sdaiUNICODE + 1
#define		engiGLOBALID			sdaiEXPRESSSTRING + 1


/*	Note on sdaiSTRING and sdaiUNICODE

	sdaiUNICODE
		this will convert all internal strings from/too unicode, the internal representation and what is written to the IFC file is mapped
			"\" will be converted into "\\" to enable basic parses to still interpret file paths
			"'" will be converted to \X1\hh\X0\ or \X2\00hh\X0\ to prevent basic interpreters to read files with strings containing these characters

	sdaiSTRING
		this will leave all information as is in the IFC file, the rules are that char's ( int ) 32 to 126 (inclusive) will be kept
		all other strings will be converted to \X1\hh\X0\ or \X2\00hh\X0\		*/


#define     sdaiARRAY               1
#define     sdaiLIST                2
#define     sdaiSET                 3
#define     sdaiBAG                 4

typedef	int				* SdaiAggr;
typedef	void			* SdaiAttr;
typedef	int				SdaiInstance;
typedef	int				SdaiInteger;
typedef	int				SdaiModel;
typedef	int				SdaiPrimitiveType;
typedef	int				* SdaiSet;
typedef	char			* SdaiString;

void	DECL STDC	engiSetComment(
										int			instance,
										char		* comment
									);

int		DECL STDC	setStringUnicode(
										int			unicode
									);

int		DECL * STDC	xxxxGetEntityAndSubTypesExtent(	//		SdaiSet
										int			model,					//			SdaiModel
										int			entity					//			SdaiEntity
									);

int		DECL * STDC	xxxxGetEntityAndSubTypesExtentBN(	//		SdaiAggr
										int			model,					//			SdaiModel
										char		* entityName			//			SdaiString
									);

int		DECL STDC	xxxxIsKindOf(                   //      SdaiBoolean
                                        int			instance,
										int			entity
									);



int		DECL * STDC	xxxxGetInstancesUsing(			//		SdaiAggr
										int			instance				//			SdaiInstance
									);

int		DECL STDC	xxxxDeleteFromAggregation(	        //		SdaiAggr
										int			instance,				//			SdaiInstance
										int			* aggregate,			//			SdaiAggr
										int			elementIndex			//			SdaiInteger
									);

void	DECL * STDC	xxxxGetAttrDefinitionByValue(	//		SdaiAttr
										int			instance,				//			SdaiInstance
										void		* value		            //			void (aggregation or instance)
									);

void	DECL STDC	xxxxGetAttrNameByIndex(          
                                        int			instance,				//			SdaiInstance
										int			index,			        //			SdaiAttr
                                        char		** name                 //          name
                                    );

int		DECL STDC	xxxxOpenModelByStream(
										int			repository,
										void		* callback,
										char		* schemaName
									);


int		DECL STDC	sdaiOpenModelBNUnicode(
										int			repository,
										void		* fileName,
										void		* schemaName
									);

int		DECL STDC	sdaiOpenModelBN(
										int			repository,
										char		* fileName,
										char		* schemaName
									);


int		DECL STDC	sdaiCreateModelBNUnicode(
										int			repository,
										void		* fileName,
										void		* schemaName
									);

int		DECL STDC	sdaiCreateModelBN(
										int			repository,
										char		* fileName,
										char		* schemaName
									);

int		DECL STDC	GetSPFFHeaderItem(
										int			model,
										int			itemIndex,
										int			itemSubIndex,
										int			valueType,
                                        char		** value
                                    );

int		DECL STDC	SetSPFFHeaderItem(
										int			model,
										int			itemIndex,
										int			itemSubIndex,
										int			valueType,
                                        char		* value
                                    );

void	DECL STDC	SetSPFFHeader(
										int			model,
                                        char	    * description,
                                        char		* implementationLevel,
                                        char		* name,
                                        char		* timeStamp,
                                        char		* author,
                                        char		* organization,
                                        char		* preprocessorVersion,
                                        char		* originatingSystem,
                                        char		* authorization,
                                        char		* fileSchema
                                    );

void	DECL STDC	sdaiSaveModelBNUnicode(
										int			model,
										void		* fileName
									);

void	DECL STDC	sdaiSaveModelBN(
										int			model,
										char		* fileName
									);

void	DECL STDC	sdaiSaveModelAsXmlBNUnicode(
										int			model,
										void		* fileName
									);

void	DECL STDC	sdaiSaveModelAsXmlBN(
										int			model,
										char		* fileName
									);

void	DECL STDC	sdaiSaveModelAsSimpleXmlBNUnicode(
										int			model,
										void		* fileName
									);

void	DECL STDC	sdaiSaveModelAsSimpleXmlBN(
										int			model,
										char		* fileName
									);

void	DECL STDC	sdaiCloseModel(
										int			model
									);

void	DECL STDC	setPreProcessing(
										int			model,
										int			on
									);

void	DECL STDC	setPostProcessing(
										int			model,
										int			on
									);

void	DECL * STDC	engiGetAggrElement(				//		void*
										int			* aggregate,			//			SdaiAggr
										int			elementIndex,			//			SdaiInteger
										int			valueType,				//			SdaiPrimitiveType
										void		* pValue				//			void*
									);

void	DECL * STDC	engiGetAggrElement_I(			//		void*
										int			* aggregate,			//			SdaiAggr
										int			elementIndex,			//			SdaiInteger
										int			valueType,				//			SdaiPrimitiveType
										void		* pValue				//			void*
									);

void	DECL STDC	engiGetAggrType(
										int			* aggregate,			//			SdaiAggr
										int			* aggragateType
									);

int		DECL STDC	engiGetInstanceMetaInfo(		//		void*
										int			* instance,				//			SdaiAppInstance
										int			* localId,				//			...
										char		** className,			//			..
										char		** classNameUC			//			...*
									);

void	DECL STDC	engiGetEntityName(
										int			entity,					//			...
										int			valueType,				//			SdaiPrimitiveType
										char		** className			//			..
									);

int		DECL STDC	engiGetEntityParent(
										int			entity					//			...
									);

void	DECL STDC	engiGetEntityProperty(
										int			entity,					//			...
										int			index,					//			...
										char		** propertyName,		//			...
										int			* optional,				//			...
										int			* type,					//			...
										int			* _array,				//			...
										int			* set,					//			...
										int			* list,					//			...
										int			* bag,					//			...
										int			* min,					//			...
										int			* max,					//			...
										int			* referenceEntity,		//			...
										int			* inverse				//			...
									);

int		DECL STDC	engiGetInstanceLocalId(			//
										int			instance				//			SdaiAppInstance
									);

void	DECL STDC	engiGetInstanceClassInfoEx(		//
										int			instance,				//			SdaiAppInstance
										void		** classInfo
									);

char	DECL * STDC	engiGetInstanceClassInfo(		//
										int			instance				//			SdaiAppInstance
									);

char	DECL * STDC	engiGetInstanceClassInfoUC(		//
										int			instance				//			SdaiAppInstance
									);
	

void	DECL STDC	sdaiAppend(						//		void
										int			list,					//			SdaiList
										int			valueType,				//			SdaiPrimitiveType
										void		* value					//			void*
									);

void	DECL STDC	sdaiBeginning(					//		void
										int			iterator				//			SdaiIterator
									);

void	DECL * STDC	sdaiCreateADB(					//		void*
										int			valueType,				//			SdaiPrimitive
										void		* value					//			void*
									);

int		DECL * STDC	sdaiCreateAggr(					//		SdaiAggr
										int			instance,				//			SdaiAppInstance
										void		* attribute				//			SdaiAttr
									);

int		DECL * STDC	sdaiCreateAggrBN(				//		SdaiAggr
										int			instance,				//			SdaiAppInstance
										char		* attributeName			//			SdaiString
									);

int		DECL STDC	sdaiCreateInstance(				//		SdaiAppInstance
										int			model,					//			SdaiModel
										int			entity					//			SdaiEntity
									);

int		DECL STDC	sdaiCreateInstanceEI(			//		SdaiAppInstance
										int			model,					//			SdaiModel
										int			entity,					//			SdaiEntity
										int			express_id				//			
									);

int		DECL STDC	sdaiCreateInstanceBN(			//		SdaiAppInstance
										int			model,					//			SdaiModel
										char		* entityName			//			SdaiString
									);

int		DECL STDC	sdaiCreateInstanceBNEI(			//		SdaiAppInstance
										int			model,					//			SdaiModel
										char		* entityName,			//			SdaiString
										int			express_id				//			
									);

void	DECL * STDC	sdaiCreateIterator(				//		SdaiIterator
										int			* aggregate				//			SdaiAggr
									);

void	DECL STDC	sdaiDeleteInstance(				//		void
										int			instance				//			SdaiAppInstance
									);

void	DECL STDC	sdaiDeleteIterator(				//		void
										int			iterator				//			SdaiIterator
									);

void	DECL STDC	sdaiEnd(						//		void
										int			iterator				//			SdaiIterator
									);

int		DECL STDC	sdaiErrorQuery(					//		SdaiErrorCode
									);

int		DECL STDC	sdaiGetADBType(					//		void
										void		* ADB	 				//			sdaiADB
									);

char	DECL * STDC sdaiGetADBTypePath(				//		void
										void		* ADB,	 				//			sdaiADB
										int			typeNameNumber			//			int
									);

void	DECL STDC	sdaiGetADBTypePathx(			//		void
										void		* ADB,	 				//			sdaiADB
										int			typeNameNumber,			//			int
										int			* result
									);

void	DECL STDC	sdaiGetADBValue(				//		void
										void		* ADB,	 				//			sdaiADB
										int			valueType,				//			SdaiPrimitiveType
										void		* value					//			void*
									);

void	DECL * STDC	sdaiGetAggrByIterator(			//		void*
										int			iterator,				//			SdaiIterator
										int			valueType,				//			SdaiPrimitiveType
										void		* value					//			void*
									);

void	DECL * STDC	sdaiGetAttr(					//		void*
										int			instance,				//			SdaiInstance
										void		* attribute,			//			SdaiAttr
										int			valueType,				//			SdaiPrimitiveType
										void		* value					//			void*
									);

void	DECL * STDC	sdaiGetAttrBN(					//		void*
										int			instance,				//			SdaiInstance
										char		* attributeName,		//			SdaiString
										int			valueType,				//			SdaiPrimitiveType
										void		* value					//			void*
									);

void	DECL * STDC	sdaiGetAttrDefinition(			//		SdaiAttr
										int			entity,					//			SdaiEntity
										char		* attributeName			//			SdaiString
									);

int		DECL STDC	sdaiGetEntity(					//		SdaiEntity
										int			model,					//			SdaiModel
										char		* entityName			//			SdaiString
									);

int		DECL * STDC	sdaiGetEntityExtent(			//		SdaiAggr
										int			model,					//			SdaiModel
										int			entity					//			SdaiEntity
									);

int		DECL * STDC	sdaiGetEntityExtentBN(			//		SdaiAggr
										int			model,					//			SdaiModel
										char		* entityName			//			SdaiString
									);

int		DECL STDC	sdaiGetInstanceType(			//		SdaiEntity
										int			instance				//			SdaiInstance
									);

int		DECL STDC	sdaiGetMemberCount(				//		SdaiInteger
										int			* aggregate				//			SdaiAggr
									);

int		DECL STDC	sdaiIsInstanceOf(				//		SdaiBoolean
										int			instance,				//			SdaiInstance
										int			entity					//			SdaiEntity
									);

int		DECL STDC	sdaiIsInstanceOfBN(				//		SdaiBoolean
										int			instance,				//			SdaiInstance
										char		* entityName			//			SdaiString
									);

int		DECL STDC	sdaiNext(						//		SdaiBoolean
										int			iterator				//			SdaiIterator
									);

void	DECL STDC	sdaiPrepend(					//		void
										int			list,					//			SdaiList
										int			valueType,				//			SdaiPrimitiveType
										void		* value					//			void*
									);

int		DECL STDC	sdaiPrevious(					//		SdaiBoolean
										int			iterator				//			SdaiIterator
									);

void	DECL STDC	sdaiPutADBTypePath(				//		void
										void		* ADB,					//			sdaiADB
										int			pathCount,				//			int
										char		* path					//			char*
									);

void	DECL STDC	sdaiPutAggrByIterator(			//		void
										int			iterator,				//			SdaiIterator
										int			valueType,				//			SdaiPrimitiveType
										void		* value					//			void*
									);

void	DECL STDC	sdaiPutAttr(					//		void
										int			instance,				//			SdaiInstance
										void		* attribute,			//			SdaiAttr
										int			valueType,				//			SdaiPrimitive
										void		* value					//			void*
									);

void	DECL STDC	sdaiPutAttrBN(					//		void
										int			instance,				//			SdaiInstance
										char		* attributeName,		//			SdaiString
										int			valueType,				//			SdaiPrimitive
										void		* value					//			void*
									);

int		DECL STDC	sdaiTestAttr(					//		SdaiBoolean
										int			instance,				//			SdaiInstance
										void		* attribute				//			SdaiAttr
									);

int		DECL STDC	sdaiTestAttrBN(					//		SdaiBoolean
										int			instance,				//			SdaiInstance
										char		* attributeName			//			SdaiString
									);



int		DECL STDC	engiGetAttrType(				//		void*
										int			instance,				//			SdaiInstance
										void		* attribute
									);

int		DECL STDC	engiGetAttrTypeBN(				//		void*
										int			instance,				//			SdaiInstance
										char		* attributeName
									);




int		DECL STDC	initializeModelling(
										int			model,
										int			* noVertices,
										int			* noIndices,
										double		scale
									);

int		DECL STDC	initializeModellingInstance(
										int			model,
										int			* noVertices,
										int			* noIndices,
										double		scale,
										int			instance				//			SdaiInstance
									);

int		DECL STDC	initializeModellingInstanceEx(
										int			model,
										int			* noVertices,
										int			* noIndices,
										double		scale,
										int			instance,				//			SdaiInstance
										int			instanceList			//			SdaiInstance
									);

int		DECL STDC	finalizeModelling(
										int			model,
										float		* pVertices,
										int			* pIndices,
										int			FVF
									);

void	DECL STDC	exportModellingAsOWL(
										int			model,
										char		* fileName
									);

void	DECL STDC	owlGetModel(
										int			model,
										int64_t		* owlModel
									);

void	DECL STDC	owlGetInstance(
										int			model,
										int			instance,
										int64_t		* owlInstance
									);

void	DECL STDC	owlGetMappedItem(
										int			model,
										int			instance,
										int64_t		* owlInstance,
										double		* transformationMatrix
									);

int		DECL STDC	getInstanceInModelling(
										int			model,
										int			instance,
										int			mode,
										int			* startVertex,
										int			* startIndex,
										int			* primitiveCount
									);

void	DECL STDC	cleanMemory(
										int			model,
										int			mode
									);

int		DECL STDC	getInstanceDerivedPropertiesInModelling(
										int			model,
										int			instance,
										double		* height,
										double		* width,
										double		* thickness
									);

int		DECL STDC	getInstanceDerivedBoundingBox(
										int			model,
										int			instance,
										double		* Ox,
										double		* Oy,
										double		* Oz,
										double		* Vx,
										double		* Vy,
										double		* Vz
									);

int		DECL STDC	getInstanceDerivedTransformationMatrix(
										int			model,
										int			instance,
										double		* _11,
										double		* _12,
										double		* _13,
										double		* _14,
										double		* _21,
										double		* _22,
										double		* _23,
										double		* _24,
										double		* _31,
										double		* _32,
										double		* _33,
										double		* _34,
										double		* _41,
										double		* _42,
										double		* _43,
										double		* _44
									);

void	DECL STDC	circleSegments(
										int			circles,
										int			smallCircles
									);

int		DECL STDC	getTimeStamp(
										int			model
									);

char	DECL * STDC	getChangedData(
										int			model,
										int			* timeStamp
									);

void	DECL STDC	setChangedData(
										int			model,
										int			* timeStamp,
										char		* changedData
									);

void	DECL * STDC	internalGetBoundingBox(
										int			model,
										int			instance
									);

void	DECL * STDC	internalGetCenter(
										int			model,
										int			instance
									);

void	DECL STDC	internalSetLink(
										int			instance,				//			SdaiInstance
										char		* attributeName,		//			SdaiString
										int			linked_id
									);

void	DECL STDC	internalAddAggrLink(					//		void
										int			list,					//			SdaiList
										int			linked_id
									);

char	DECL * STDC	sdaiGetStringAttrBN(
										int			instance,
										char		* attributeName
									);

int		DECL STDC	sdaiGetInstanceAttrBN(
										int			instance,
										char		* attributeName
									);

int		DECL STDC	sdaiGetAggregationAttrBN(
										int			instance,
										char		* attributeName
									);

int		DECL STDC	internalGetP21Line(
										int			instance				//			SdaiAppInstance
									);

int		DECL STDC	internalGetInstanceFromP21Line(
										int			P21Line				//			Part 21 Express line no
									);

void	DECL STDC	engiGetNotReferedAggr(
										int			model,
										int			* pValue
									);

void	DECL STDC	engiGetAttributeAggr(
										int			instance,
										int			* pValue
									);

void	DECL STDC	engiGetAggrUnknownElement(		//		void
										int			* aggregate,			//			SdaiAggr
										int			elementIndex,			//			SdaiInteger
										int			* valueType,			//			SdaiPrimitiveType
										void		* pValue				//			void*
									);

int		DECL STDC	sdaiIsKindOf(
										int			instance,
										int			entity
									);

int		DECL * STDC	sdaiFindInstanceUsers(
										int			instance,
										int			* domain,
										int			* resultList
									);

int		DECL * STDC	sdaiFindInstanceUsedIn(
										int			instance,
										int			* domain,
										int			* resultList
									);

int		DECL STDC	sdaiplusGetAggregationType(
										int			instance,
										int			* aggregation
									);

int		DECL STDC	engiGetEntityNoArguments(
										int			entity
									);

void	DECL STDC	engiGetEntityArgumentName(
										int			entity,
										int			index,
										int			valueType,				//			SdaiPrimitiveType
										char		** argumentName			//			..
									);

void	DECL STDC	engiGetEntityArgumentType(
										int			entity,
										int			index,
										int			* argumentType			//			..
									);

int		DECL STDC	getInstanceProfile(
										int			model,
										int			instance,
										double		* vertexBuffer,
										int			vertexBufferSize
									);

void	DECL STDC	setVertexOffset(
										int			model,
										double		x,
										double		y,
										double		z
									);

void	DECL STDC	setFormat(
										int			model,
										int			setting,
										int			mask
									);

int		DECL STDC	getConceptualFaceCnt(
										int			instance
									);

int		DECL STDC	getConceptualFaceEx(
										int			instance,
										int			index,
										int			* startIndexTriangles,
										int			* noIndicesTriangles,
										int			* startIndexLines,
										int			* noIndicesLines,
										int			* startIndexPoints,
										int			* noIndicesPoints,
										int			* startIndexFacesPolygons,
										int			* noIndicesFacesPolygons,
										int			* startIndexConceptualFacePolygons,
										int			* noIndicesConceptualFacePolygons
									);

int		DECL STDC	iterateOverInstances(
										int			model,
										int			instance,
										int			* entity,
										void		* entityName
									);

int		DECL STDC	iterateOverProperties(
										int			entity,
										int			index
									);

void DECL STDC	createGeometryConversion(
										int			instance,
										int64_t		* owlInstance
									);

#ifdef __cplusplus
	}
#endif

#undef DECL 
#undef STDC  
#undef int
