CREATE TABLE [dbo].[Suppliers] (
    [Id_suppliers] INT        IDENTITY (1, 1) NOT NULL,
    [s_name]       NCHAR (20) NOT NULL,
    [s_surname]    NCHAR (20) NULL,
    [s_patronimyc] NCHAR (20) NULL,
    [s_mobile]     NCHAR (15) NOT NULL,
    PRIMARY KEY CLUSTERED ([Id_suppliers] ASC)
);

